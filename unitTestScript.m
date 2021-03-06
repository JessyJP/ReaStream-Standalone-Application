%% Codegen prep script
clc; 
clear all;

    global STATE_IN_LOOP_FLAG_;% Global interupt flag
    STATE_IN_LOOP_FLAG_ = true;
    
    global FLUSH_UDP_BUFFER_FLAG_; 
    FLUSH_UDP_BUFFER_FLAG_ = false;
    
    global GlobalByteBuffer_ Gi_;
    filename = 'UDPdataForTesting.mat';
    data = load(filename,'GlobalByteBuffer_');
    GlobalByteBuffer_ = data.GlobalByteBuffer_;
    Gi_ = 0;    
    
    global myApp;
    % Debug and interface
%     myApp.DebugONCheckBox.Value = false;
%     myApp.ScopeCheckBox.Value = false;
%     myApp.scopeSetupDone_FLAG = false;
%     myApp.UPD_bufferSizes = zeros(round(48000/128),1);   
    
    
    % Input or input from interface
    myApp.ReceiverIPEditField.Value = '0.0.0.0';% Defaul;
    myApp.ReceiverPortEditField.Value  = 58710;% Default;
    myApp.ReaStreamIdentifierDropDown.Value = 'ReaperMainOut';% Default
    myApp.AudioDriverDropDown.Value = 'DirectSound';% Default
    myApp.DeviceDropDown.Value = 'Default';% Default
    myApp.PlaybackSampleSizeEditField.Value = 128;% Default
    myApp.VariableBufferCheckBox.Value = true;% Default 
    
    load('rsFrameHeader2Struct.mat')
    audioFrame = rsFrameHeader2Struct(uint8(zeros(1,43)));
    
    % Run the main process function
    MainProcess('ReaperMainOut','DirectSound','Default',128,true)   

%     obj = ReaStreamReceiver(myApp);
    obj.runMainReceptionProcess();
return;


%% SaveUDPoutputDataForTesting.m
tic
global GlobalByteBuffer_;
if ~isempty(GlobalByteBuffer_)
    filename = 'UDPdataForTesting.mat';
    save(filename,'GlobalByteBuffer_');
    GlobalByteBuffer_ = [];
end
toc

return;