close all;clc;clear all;
%% Add paths
addpath(genpath("."))
outputfile = "UDPdataForTesting.mat";

%% Make test file
if false
    global GlobalByteBuffer_ Ri_ Gi_
    GlobalByteBuffer_=[];Ri_=[]; Gi_=[];
    
    hexStream = '4d5253521f02000052656173747265616d204964656e746966696572204c6162656c0000000000000180bb0000f001aa6fd93d2a3b033e5371183e76242c3e8e223e3eef3d4e3eb24d5c3e252e683e22c1713e59ee783e91a37d3ed8d47f3e9b7c7f3ebc9b7c3e8939773eac636f3e0b2e653e91b2583eef104a3e4a6e393edef4263e92d3123e057bfa3df8d2cc3de8229d3dcec7573def4be63c93fc553bb310b1bcb78f3dbde95a90bd787fc0bd4fbbeebd864c0dbeaad421bef1c134be4ee445be421055be481f62be37f06cbe9c6775bef66f7bbef4f97ebe9cfc7fbe5c757ebe15687abe11df73bee8ea6abe54a25fbefc2152be268c42be640831be2ec31dbe6fed08be1c78e5bdc5ceb6bd505586bd9d0d29bdce8687bc63cb083c45d2073dde186c3d0704a73d9953d63d84c1013ece0f173e93de2a3e89fb3c3eb4384d3ed96c5b3ee973673e5b2f713e7a86783ea1667d3e72c37f3eec967f3e80e17c3e0faa773ed7fd6f3e54f0653e0a9b593e491d4b3edc9b3a3eab40283e503a143e4477fd3d66f6cf3d8d65a03df97a5e3d01ecf33c24dba13b2a65a3bc24d136bdc70f8dbddb50bdbd4cb1ebbdaddd0bbe9c7f20be108a33beb3cc44beb21b54be2f5061bea5486cbe38e974be021c7bbe47d17ebe9bff7fbe00a47ebee7c17abe2e6374beff976bbeaf7660be801b53be59a843be744432bef91b1fbe8a5f0abe9a87e8bdc501babdb4a389bd62d02fbdff3595bc60beda3b2c05013d';
    GlobalByteBuffer_=uint8([]);% Local variable but when saved to .mat it will be loadedinto a global variable
    for i = 1:numel(hexStream)/2
        str=['GlobalByteBuffer_=','[GlobalByteBuffer_,','0x',hexStream([1:2]+(i-1)*2),'];'];
        eval(str);
    end
    
    GlobalByteBuffer_ = repmat(GlobalByteBuffer_,1,1);
    save(outputfile,"GlobalByteBuffer_");

end
%% Run 
if true
    global GlobalByteBuffer_ Ri_ Gi_

    

    
    obj = ReaStreamReceiver();
    % obj.ReaStreamIDtag = 'Reastream Identifier Label';
    obj.DEBUG_BUFFER_REALTIME_FLAG  = false;
%     obj.DEBUG_BUFFER_RECORD_FLAG    = true;
    obj.DEBUG_BUFFER_PLAYBACK_FLAG  = true;
    % obj.DEBUG_STORE_FRAME_FLAG = true;

    if obj.DEBUG_BUFFER_RECORD_FLAG
        GlobalByteBuffer_ = uint8(zeros(1,4*60*48000*2*4));
        Ri_ = 0; 
        Gi_ = 0;
    end
    if obj.DEBUG_BUFFER_PLAYBACK_FLAG
        GlobalByteBuffer_=[];Ri_=[]; Gi_=[];
    end
        

    obj.runMainProcess()
    
    if obj.DEBUG_BUFFER_RECORD_FLAG
        try
            GlobalByteBuffer_(Ri_+1:end) = [];
        end
        save(outputfile,"GlobalByteBuffer_");
        return
    end 

end
return
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
compareByteBuffer(GlobalByteBuffer_,B);

return
%% Generate test wave
clc;

S = rsFrameHeader2Struct([]);
    S.streamName  = 'input';
    S.numChannels = 1;
    S.SampleRate  = 48000;

disp(S)



GlobalByteBuffer_ = rsFrame2UDPbyteArray(S);
GlobalByteBuffer_ = repmat(GlobalByteBuffer_,1,1);
save(outputfile,"GlobalByteBuffer_");

return
%% Transmission Test
clc;
try;fclose(obj.TransmitterUDP);end
clear;% Clear the workspace

% Setup Transmitter object 
obj = ReaStreamTransmitter();
% obj.TransmitterIP = '127.255.255.255';
% obj.TransmitterIP = '192.168.0.101';
obj.TransmitterIP = '192.168.0.255';
% obj.TransmitterIP = 'localhost';
% obj.ReaStreamIDtag = 'input';
obj.ReaStreamIDtag = 'Reastream Identifier Label';


% obj.connectTransmitterUDP();
obj.TransmitterUDP = ...
    udp(obj.TransmitterIP,obj.Port);
%     udp('', 'LocalHost', '', 'LocalPort', 8000);
    
% obj.TransmitterUDP.EnablePortSharing = 'on';
SampLenth = 300;
obj.TransmitterUDP.OutputBufferSize = SampLenth*4+47;
% obj.TransmitterUDP.OutputDatagramSize = 1247

fopen(obj.TransmitterUDP);


for s = 1:1
    % Make reastream frame
    S = rsFrameHeader2Struct([]);
        S.streamName  = obj.ReaStreamIDtag;
        S.numChannels = 3;
        S.SampleRate  = 48000;
    
        % Generate test wave
%         waveGenerate = @(t,FQ) sin(2*pi*FQ*t);
%         dB = -3;
%         t = ((1:SampLenth)+SampLenth*(s-1))/S.SampleRate;
%         S.audioFrameBuff = 10^(dB/20)*waveGenerate(t,s);
        S.audioFrameBuff = (1:30)/100;
        % Convert buffer
        S.audioFrameBuff = single(S.audioFrameBuff);
        
    % Convert to byte array
    B = rsFrame2UDPbyteArray(S);
    % Send the buffer to the server
    sendUDPbuffer(obj,B);
    disp("Sent:"+s)

    % Check the frame
    if false% check
        obj.DEBUG_BUFFER_REALTIME_FLAG=false;
        obj.DEBUG_BUFFER_PLAYBACK_FLAG=true;

        setGlobalByteBuffer(B);% Seth the global byte buffer

        [audioFrame,STATE_FLAG_,totalBytesRead] = readReaStreameFrame(obj);
        obj.DEBUG_BUFFER_REALTIME_FLAG=true;
        obj.DEBUG_BUFFER_PLAYBACK_FLAG=false;
    end
    pause(S.timeLength_ms*0.001);
end
totalTime = (s*SampLenth/S.SampleRate)
disp(totalTime)
% obj.disconnectTransmitterUDP();
fclose(obj.TransmitterUDP);
