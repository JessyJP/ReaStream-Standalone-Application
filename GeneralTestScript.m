close all;clc;clear all;
%% Add paths
addpath(genpath("."))

%% Make test file

hexStream = '4d5253521f02000052656173747265616d204964656e746966696572204c6162656c0000000000000180bb0000f001aa6fd93d2a3b033e5371183e76242c3e8e223e3eef3d4e3eb24d5c3e252e683e22c1713e59ee783e91a37d3ed8d47f3e9b7c7f3ebc9b7c3e8939773eac636f3e0b2e653e91b2583eef104a3e4a6e393edef4263e92d3123e057bfa3df8d2cc3de8229d3dcec7573def4be63c93fc553bb310b1bcb78f3dbde95a90bd787fc0bd4fbbeebd864c0dbeaad421bef1c134be4ee445be421055be481f62be37f06cbe9c6775bef66f7bbef4f97ebe9cfc7fbe5c757ebe15687abe11df73bee8ea6abe54a25fbefc2152be268c42be640831be2ec31dbe6fed08be1c78e5bdc5ceb6bd505586bd9d0d29bdce8687bc63cb083c45d2073dde186c3d0704a73d9953d63d84c1013ece0f173e93de2a3e89fb3c3eb4384d3ed96c5b3ee973673e5b2f713e7a86783ea1667d3e72c37f3eec967f3e80e17c3e0faa773ed7fd6f3e54f0653e0a9b593e491d4b3edc9b3a3eab40283e503a143e4477fd3d66f6cf3d8d65a03df97a5e3d01ecf33c24dba13b2a65a3bc24d136bdc70f8dbddb50bdbd4cb1ebbdaddd0bbe9c7f20be108a33beb3cc44beb21b54be2f5061bea5486cbe38e974be021c7bbe47d17ebe9bff7fbe00a47ebee7c17abe2e6374beff976bbeaf7660be801b53be59a843be744432bef91b1fbe8a5f0abe9a87e8bdc501babdb4a389bd62d02fbdff3595bc60beda3b2c05013d';
output_=uint8([]);
for i = 1:numel(hexStream)/2
    str=['output_=','[output_,','0x',hexStream([1:2]+(i-1)*2),'];'];
    eval(str);
end
outputfile = "UDPdataForTesting.mat";

output_ = repmat(output_,1,1);
save(outputfile,"output_");

%% Run 

obj = ReaStreamReceiver();
obj.ReaStreamIDtag = 'Reastream Identifier Label';
obj.DEBUG_BUFFER_REALTIME_FLAG  = false;
obj.DEBUG_BUFFER_RECORD_FLAG    = false;
obj.DEBUG_BUFFER_PLAYBACK_FLAG  = true;
obj.DEBUG_STORE_FRAME_FLAG = true;
obj.runMainProcess()

%% Frame Validation
% clc;

% Test 1
B = rsFrame2UDPbyteArray(obj.FrameBuffer);

% Test 2
S = rsFrameHeader2Struct([]);
    S.streamName     = obj.FrameBuffer.streamName;
    S.numChannels    = obj.FrameBuffer.numChannels;
    S.SampleRate     = obj.FrameBuffer.SampleRate;
    S.audioFrameBuff = obj.FrameBuffer.audioFrameBuff;
B = rsFrame2UDPbyteArray(S);

% Test 3
S = makeFrame( ...
    obj.FrameBuffer.streamName, ...
    obj.FrameBuffer.numChannels, ...
    obj.FrameBuffer.SampleRate, ...
    obj.FrameBuffer.audioFrameBuff);
B = rsFrame2UDPbyteArray(S);

% Check the conversion
ind = numel(B);
clear TBL;
    TBL.Index = (1:ind)';
    TBL.Original = output_(1:ind)';
    TBL.New = B(1:ind)';
    TBL.check = output_(1:ind)' == B(1:ind)';
    TBL = struct2table(TBL);
disp(TBL(TBL.check==false,:))

return
%% Generate test wave
clc;

S = rsFrameHeader2Struct([]);
    S.streamName  = 'input';
    S.numChannels = 1;
    S.SampleRate  = 48000;

disp(S)



output_ = rsFrame2UDPbyteArray(S);
output_ = repmat(output_,1,1);
save(outputfile,"output_");

%% Transmit Test
TransmitterIP= "localhost"


%% Local Test functions


 