%% Codegen prep script
clc; 
clear all;

    global STATE_IN_LOOP_FLAG_;% Global interupt flag
    STATE_IN_LOOP_FLAG_ = true;
    
    global FLUSH_UDP_BUFFER_FLAG_; 
    FLUSH_UDP_BUFFER_FLAG_ = false;
    
    global output_ i;
    filename = 'UDPdataForTesting.mat';
    data = load(filename,'output_');
    output_ = data.output_;
    i = 0;    
    
    global myApp;
    % Debug and interface
%     myApp.DebugONCheckBox.Value = false;
%     myApp.ScopeCheckBox.Value = false;
%     myApp.scopeSetupDone_FLAG = false;
%     myApp.UPD_bufferSizes = zeros(round(48000/128),1);   
    
    
    % Input or input from interface
    myApp.IPEditField.Value = '0.0.0.0';% Defaul;
    myApp.PortEditField.Value  = 58710;% Default;
    myApp.ReaStreamIdentifierDropDown.Value = 'ReaperMainOut';% Default
    myApp.AudioDriverDropDown.Value = 'DirectSound';% Default
    myApp.DeviceDropDown.Value = 'Default';% Default
    myApp.PlaybackSampleSizeEditField.Value = 128;% Default
    myApp.VariableBufferCheckBox.Value = true;% Default 
    
    load('rsFrameHeader2Struct.mat')
    audioFrame = rsFrameHeader2Struct(uint8(zeros(1,43)));
    
    % Run the main process function
    MainProcess('ReaperMainOut','DirectSound','Default',128,true)   

%     obj = ReaStreamAndroidReciever(myApp);
%     obj.runMainProcess();
return;


%% SaveUDPoutputDataForTesting.m
tic
global output_;
if ~isempty(output_)
    filename = 'UDPdataForTesting.mat';
    save(filename,'output_');
    output_ = [];
end
toc

return;
   
%% function unitTestScript2()
% Add Path
addpath('unitTestInputData\');

% readReaStreameFrame -- UNIT TEST
load('readReaStreameFrame.mat');
obj.udp = udpport(...
    "LocalHost",obj.IP,...
    "LocalPort",obj.Port,...
    "EnablePortSharing",true,"Timeout",obj.TimeOut);

% Read reastream frame
[Frame,STATE_FLAG_] = readReaStreameFrame(obj);
return;