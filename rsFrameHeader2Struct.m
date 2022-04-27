function [S] = rsFrameHeader2Struct(F)
% function [S,i] = rsFrameHeader2Struct(F)
% Unpack ReaStream Frame Header to a Structure
% The input is expected as uint8 byte stream
%
%     typedef struct ReaStream
%     {
%     char ID[4]; // 'MRSR' tag for every packet like an ID (4 bytes)
%     unsigned int packetSize; // size of the entire UDP packet (4 bytes)
%     char name[32]; // Name of the stream (ie: default on the plugin) (32 bytes)
%     unsigned int nbChan; // the number of channels the plugin sends (1 byte)
%     unsigned int freq; // the rate Frequency of the data (44100, 48000, ...) (4 bytes)
%     unsigned datasSize; // size of the following bytes to read. (2 bytes)
%     float *datas; // start of the audio datas (variable get from "datasSize")
%     } ReaStream;

    % Frame Output template
    S.udpPayLoadBytes = 0;
    coder.varsize('S.streamName',[1,32]);
    S.streamName = char('');
    S.numChannels = 0;
    S.SampleRate = 0;
    S.audioByteLength = 0;
    S.bufferSize = 0;
    S.timeLenght = 0;
    coder.varsize('S.audioFrameBuff');
    S.audioFrameBuff = single([]);
    
    if isempty(F)
        return;
    end

    % ID (4 bytes)
    ID = char( F(1:4) );
    if strcmp(ID,'MRSR')
        i=4;
    else
        i=0;
    end

    % DataSize (4 bytes)
    S.udpPayLoadBytes=double(typecast( F(i+1:i+4) ,'uint32'));
    i=i+4;

    % Stream Name (32 bytes)
    streamName = char(F(i+1:i+32))+0;
    S.streamName = char(streamName(streamName>0));
    i = i+32;

    % Number of channels (1 bytes)
%     S.numChannels = double( F(i+1:i+1) );
    S.numChannels = double( F(i+1) );
    i=i+1;

    % DataSize (4 bytes)
    S.SampleRate = double(typecast( F(i+1:i+4) ,'uint32'));
    % dec2hex( F(i+1:i+4))
    i=i+4;

    % ID (2 bytes)
    S.audioByteLength= double(typecast( F(i+1:i+2),'uint16'));
    i=i+2;

    % Compute buffer
    S.bufferSize = S.audioByteLength/(S.numChannels*4);
    S.timeLenght = 1000*S.bufferSize/S.SampleRate;
    
    % Audio Buffer to be read
    S.audioFrameBuff = single([]);
end


%     % DataSize (4 bytes)
%     udpPayLoadBytes=double(typecast( F(i+1:i+4) ,'uint32'));
%     i=i+4;
% 
%     % Stream Name (32 bytes)
%     streamName = char(F(i+1:i+32))+0;
%     streamName = char(streamName(streamName>0));
%     i = i+32;
% 
%     % Number of channels (1 bytes)
% %     S.numChannels = double( F(i+1:i+1) );
%     numChannels = double( F(i+1) );
%     i=i+1;
% 
%     % DataSize (4 bytes)
%     SampleRate = double(typecast( F(i+1:i+4) ,'uint32'));
%     % dec2hex( F(i+1:i+4))
%     i=i+4;
% 
%     % ID (2 bytes)
%     audioByteLength= double(typecast( F(i+1:i+2),'uint16'));
%     i=i+2;
% 
%     % Compute buffer
%     bufferSize = audioByteLength/(numChannels*4);
%     timeLenght = 1000*bufferSize/SampleRate;
%     
%     % Audio Buffer to be read
%     audioFrameBuff = single(0);
%     
%     %% Assign to Frame
%     % Frame Output template
%     S.udpPayLoadBytes = udpPayLoadBytes;
%     S.streamName = streamName;
%     S.numChannels = numChannels;
%     S.SampleRate = SampleRate;
%     S.audioByteLength = audioByteLength;
%     S.bufferSize = bufferSize;
%     S.timeLenght = timeLenght;
%     S.audioFrameBuff = audioFrameBuff;