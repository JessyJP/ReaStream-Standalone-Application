function [B] = rsFrame2UDPbyteArray(F)
% function [B] = rsFrame2UDPbyteArray(F)
% Pack ReaStream Frame to a byte array 
%
% The input is the ReaStream Frame
% The output is uint8 byte stream
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
    if isempty(F)
        return;
    end

    audioByteLength = numel(F.audioFrameBuff)*4;
    % Type casting
    C = @(x) typecast(x,'uint8');

    % Make the lable to correct size
    if numel(F.streamName) > 32
        F.streamName = F.streamName(1:32);
    elseif numel(F.streamName) < 32
        F.streamName = [F.streamName , repmat(char(0),1,32-numel(F.streamName))];
    end

    B = [
            C(uint8('MRSR')),...
            C(uint32(audioByteLength+47)),...
            C(uint8(F.streamName)),...
            C(uint8(F.numChannels)),...
            C(uint32(F.SampleRate)),...
            C(uint16(audioByteLength)),...
            C(F.audioFrameBuff(:)')...
        ];

end