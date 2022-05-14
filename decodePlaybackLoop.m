function [obj] = decodePlaybackLoop(obj)
% function  [obj] = decodePlaybackLoop(obj)
% Unpack ReaStream Frame and Play Audio

    % Control Flags
    global STATE_IN_LOOP_FLAG_;% Global interupt flag
    global FLUSH_UDP_BUFFER_FLAG_; 
    FLUSH_UDP_BUFFER_FLAG_ = false;
    STATE_FLAG_ = obj.PROCESSING_ON_STATE_;

    % Playback Settings
    coder.varsize('playbackBuffer');
    playbackBuffer = single([]);
    
    % Clear the UDP buffer before starting to decode
    flushUDPbuffer(obj);
    % Frame count
    f=1;
    % Loop
    while STATE_IN_LOOP_FLAG_ && not(STATE_FLAG_ == obj.EXIT_STATE_)% External and Internal interupt flags

        % Read reastream frame
        [Frame,STATE_FLAG_] = readReaStreameFrame(obj);

        % This will force update the UI but not unless there is normal
        % transmission frames
        
        if mod(f,obj.PacketsPerUIrefresh)==0
            if coder.target('MATLAB')
                drawnow;% Refresh UI rate   
            end
        end 
        
        % Control logic Check flags
        if (STATE_FLAG_ == obj.SKIP_FRAME_STATE_) || (STATE_FLAG_ == obj.NO_TRANSMISSION_STATE_)
            continue;
        end    
        if FLUSH_UDP_BUFFER_FLAG_
            flushUDPbuffer(obj);
            FLUSH_UDP_BUFFER_FLAG_ = false;
        end

        % External interupt switch!
        if not(STATE_IN_LOOP_FLAG_) 
            if (STATE_FLAG_ == obj.NO_TRANSMISSION_STATE_)
                disp(' --- Disconnect due to empty transmission! --- ');
            end
            break;
        end

        %  IGNORE+++START
        if coder.target('MATLAB')  
%             updateScopeInLoopScript;
        end
        %  IGNORE+++END

        % Sent to Device with variable size bufffer
        if obj.VariableBufferON
            obj.deviceWriter(Frame.audioFrameBuff);
        else
            % Reset the buffer size if the channel number changes
            if size(playbackBuffer,2)~=size(Frame.audioFrameBuff,2)
                playbackBuffer = single([]);
            end
            % Add to buffer
            coder.varsize('playbackBuffer');
            playbackBuffer = [playbackBuffer;Frame.audioFrameBuff];       
            % Sent to Device with fixed size bufffer
            if size(playbackBuffer,1) >= obj.pbSampSize         
                obj.deviceWriter(playbackBuffer(1:obj.pbSampSize,:));
                playbackBuffer(1:obj.pbSampSize,:)=[];
            end
        end


            % Debug %  IGNORE+++START
            if coder.target('MATLAB')  
                % Debug Scripts
%                 debugInLoopScript;
            end
            %  IGNORE+++END

        % Increment frame only when the whole routine is complete
        f = f+1;
    end
end     