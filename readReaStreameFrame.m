function [audioFrame,STATE_FLAG_,totalBytesRead] = readReaStreameFrame(obj)
% function [audioFrame,STATE_FLAG_,totalBytesRead] = readReaStreameFrame(obj)
    
    % Default output
%     audioFrame = [];% Get Empty frame  
    totalBytesRead = 0;
    
    % Default output state
    STATE_FLAG_ = double(obj.PROCESSING_ON_STATE_);
      
    % Locate 'MRSR'
    timer = tic();
    while true
        % TODO NOTE: technically the there might be some random bites in
        % between. The reading of the buffer assumes the frames are one
        % after the other and even if they are not it should be able to
        % recover the correct position as long as 1,2 or 3 bytes don't
        % offset the tag, as we are reading 4 bites at the time. One way to
        % compensate for this possible issue is to keep the last tag buffer 
        % and therefore search for the 4 byte tag in an 8 tag buffer and if
        % the tag is located we can reset the possibiton. 
        % However, this problem has never occured therefore there was no
        % need for such tag position reset.
        
        tag = readUDPbuffer(obj,obj.startTgLen,'uint8');
        totalBytesRead = totalBytesRead + obj.startTgLen;% Add the numder of bytes read
        % If a frame is located
        if strcmp(obj.frameStart,char(tag))
            break;
        end
%         disp('UDP TIMEOUT!');% DEBUG++++++++++++++

        % There is a limit to the number of attemtps in order to return
        % control to the main loop and check for interupts before checking
        % the buffer again
        if toc(timer) > obj.TimeOut
            STATE_FLAG_ = obj.NO_TRANSMISSION_STATE_;
            audioFrame = rsFrameHeader2Struct(uint8(zeros(1,43)));% Get Empty frame   
            return;
        end  
    end
    
    
    % Read header
    ReaStreamHeaderByteLen=47-4;% remove 4 bytes frameID bytes becuase it was located earlier
    frameHeader = readUDPbuffer(obj,ReaStreamHeaderByteLen,'uint8');
    frameHeader = uint8(frameHeader);% Make Sure the "frameHeader" not stored as double
    totalBytesRead = totalBytesRead + ReaStreamHeaderByteLen;% Add the numder of bytes read
    audioFrame = rsFrameHeader2Struct(frameHeader);% Convert the byte stream to a structure
    
    % If the tag does not match discard the audio buffer
    if not(strcmpi(audioFrame.streamName,strtrim(obj.ReaStreamIDtag)))
%         clc;disp(Frame);
%         disp('REJECT FRAME!');% DEBUG++++++++++++++
        % Discard this packet payload
        readUDPbuffer(obj,audioFrame.audioByteLength/obj.ByteDepth,'single');
        totalBytesRead = totalBytesRead + audioFrame.audioByteLength;% Add the numder of bytes read
        STATE_FLAG_ = obj.SKIP_FRAME_STATE_;
        return;
    end
    
    % Read Audio
    audioFrame.audioFrameBuff = readUDPbuffer(obj,audioFrame.audioByteLength/obj.ByteDepth,'single');
    audioFrame.audioFrameBuff = reshape(audioFrame.audioFrameBuff,[],audioFrame.numChannels);
    totalBytesRead = totalBytesRead + audioFrame.audioByteLength;% Add the numder of bytes read
%     disp(totalBytesRead);
end
    