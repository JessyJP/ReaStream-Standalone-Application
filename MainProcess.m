function MainProcess(ReaStreamIDtag,driverSelection,deviceSelection,pbSampSize,VariableBufferON)
% function MainProcess()
    % Main Process Script

    %% Settings and Properties
    % Main loop interupt
    global STATE_IN_LOOP_FLAG_;% Global interupt flag

    obj = setDefaultProperties();
        
        if coder.target('MATLAB')
%             global myApp;
%             if not(isempty(myApp))
%                 % Input from interface
%                 obj.ReceiverIP = myApp.ReceiverIPEditField.Value;
%                 obj.Port = myApp.ReceiverPortEditField.Value;
%                 obj.ReaStreamIDtag = myApp.ReaStreamIdentifierDropDown.Value;
%                 obj.driverSelection = myApp.AudioDriverDropDown.Value;
%                 obj.deviceSelection = myApp.DeviceDropDown.Value;
%                 obj.pbSampSize = myApp.PlaybackSampleSizeEditField.Value;
%                 obj.VariableBufferON = myApp.VariableBufferCheckBox.Value;
%             end
        else
            obj.ReaStreamIDtag = ReaStreamIDtag;
            obj.driverSelection = driverSelection;
            obj.deviceSelection = deviceSelection;
            obj.pbSampSize = pbSampSize;
            obj.VariableBufferON = VariableBufferON;
        end

    disp(' +++ Settings Ready! +++ ');
%     disp(obj);

    %% Setup UPD connection   
    [obj] = connectReceiverUDP(obj);

    %% Setup the audio device with default settings
    % Check and listen for Frames
    [testFrame,STATE_FLAG_NEEDED] = readReaStreameFrame(obj);
    while (STATE_FLAG_NEEDED ~= obj.PROCESSING_ON_STATE_)
        [testFrame,STATE_FLAG_NEEDED] = readReaStreameFrame(obj);
        drawnow;
        if not(STATE_IN_LOOP_FLAG_)
            [obj] = disconnectReceiverUDP(obj);
            return;
        end
    end

    obj.SampleRate = testFrame.SampleRate;
    % Setup Audio Device Based on the header
    obj = SetupAudioDevice(obj);

    % Check if audio device is available
    if strcmpi(obj.deviceWriter.Device,'No audio output device detected')
        disp(' --- Audio device not found!!!! --- ');
        release(obj.deviceWriter);
        
        [obj] = disconnectReceiverUDP(obj);
        return;
    end

    %% Run Decode and Playback Loop
    if obj.UDP_CONNECTION_READY_FLAG && obj.AUDIO_DEVICE_READY_FLAG
        disp(' +++ Listen for Audio transmissions! +++ ');
        % profile on
        obj = decodePlaybackLoop(obj);
        % profile off
        % profile viewer
        disp(' --- Stop Listening for Audio transmissions! --- ');
    end

    %% Release UDP & audio device and hide debug settings
    % Clear the UDP connection
    [obj] = disconnectReceiverUDP(obj);

    % Release the audio device
    if obj.AUDIO_DEVICE_READY_FLAG
        disp(' --- Audio device disconnected! --- ');
        release(obj.deviceWriter); obj.AUDIO_DEVICE_READY_FLAG = false;
    end

end

function [obj] = setDefaultProperties()
    % Settings and Properties              
    % Connection Properties
    obj.ReceiverIP = '0.0.0.0';% Default
    obj.Port = 58710;% Default
    obj.TimeOut = 1;
    % UDP handle
    obj.ReceiverUDP = [];
    obj.UDP_CONNECTION_READY_FLAG = false;

    % Reastream ID tag
    obj.ReaStreamIDtag = 'ReaperMainOut';% Default

    % Audio settings
    obj.driverSelection = 'DirectSound';% Default
    obj.deviceSelection = 'Default';% Default
    obj.ByteDepth = 32/8;% Default
    %#codegen
    obj.bitDepthStrings = {'8-bit integer', '16-bit integer' , '24-bit integer' , '32-bit float'};
    obj.frameStart = 'MRSR';
    obj.startTgLen = numel('MRSR');
    obj.SampleRate = 48000;
    % Buffer size
    obj.pbSampSize = 128;% Default
    obj.VariableBufferON = true;% Default
    % Buffer for debuging and testing
    obj.DEBUG_BUFFER_REALTIME_FLAG  = true
    obj.DEBUG_BUFFER_RECORD_FLAG    = false;
    obj.DEBUG_BUFFER_PLAYBACK_FLAG  = false;            
    obj.DEBUG_STORE_FRAME_FLAG      = false;
    obj.FrameBuffer = [];

    % Device Writer Handle
    obj.deviceWriter = audioDeviceWriter('SampleRate',48000,'SupportVariableSizeInput',true);
    obj.AUDIO_DEVICE_READY_FLAG = false;

    % Operation Flags ENUMERATION
    obj.PROCESSING_ON_STATE_ = 1;% Main Processing state
    obj.EXIT_STATE_ = 0;% Interupt state to exit the main loop
    obj.SKIP_FRAME_STATE_ = 2;% Sate to skip frame
    obj.NO_TRANSMISSION_STATE_ = -1;% State to indicate no transmission

    % Debug and interface
    obj.PacketsPerUIrefresh = 100;
end

function [obj] = connectReceiverUDP(obj)
% function [obj] = connectReceiverUDP(obj)
    % Setup UPD connection
    if coder.target('MATLAB')  
        obj.ReceiverUDP = udpport(...
            "LocalHost",obj.ReceiverIP,...
            "LocalPort",obj.Port,...
            "EnablePortSharing",true,"Timeout",obj.TimeOut);
        disp(obj.ReceiverUDP);     
    end
    obj.UDP_CONNECTION_READY_FLAG = true;
    disp(' +++ UDP port opened and listening! +++ ');
end

function [obj] = disconnectReceiverUDP(obj)
    % Clear the UDP object
    if coder.target('MATLAB')
        obj.ReceiverUDP.delete();
    end
    disp(' --- Stop listening port! --- ');
    obj.UDP_CONNECTION_READY_FLAG = false;
end



% function [obj] = SetupAudioDevice(obj)
%     % Setup Audio Device Based on the header
%     if not(obj.AUDIO_DEVICE_READY_FLAG)
% 
%     % Setup Audio device
%     obj.deviceWriter = audioDeviceWriter(...
%         'Driver',obj.driverSelection,...
%         'Device',obj.deviceSelection,...
%         'SampleRate',obj.SampleRate,...
%         'BitDepth',obj.bitDepthStrings{obj.ByteDepth},...
%         'BufferSize',obj.pbSampSize,...
%         'SupportVariableSizeInput',obj.VariableBufferON);
% 
%         % Display
%         disp(' +++ Audio device connected! +++ ');
%         disp(obj.deviceWriter);
% 
%         % Done
%         obj.AUDIO_DEVICE_READY_FLAG = true;
%     end
% end

function [obj] = SetupAudioDevice(obj)
    driverSelection_ = 'DirectSound';%obj.driverSelection
    deviceSelection_ = 'Default';%deviceSelection.deviceSelection
    SampleRate_ = 48000;%obj.SampleRate
    bitDepthStrings_ ='32-bit float';%obj.bitDepthStrings{obj.ByteDepth}
    pbSampSize_ =128;
    SupportVariableSizeInput_=true;

    % Setup Audio Device Based on the header
    if not(obj.AUDIO_DEVICE_READY_FLAG)

         % Setup Audio device
%         obj.deviceWriter.Driver = 'DirectSound';
%         obj.deviceWriter.Device = deviceSelection_;
%         obj.deviceWriter.SampleRate = SampleRate_;
%         obj.deviceWriter.BitDepth = bitDepthStrings_;%Settings.ByteDepth
%         obj.deviceWriter.BufferSize = pbSampSize_;
%         obj.deviceWriter.SupportVariableSizeInput = SupportVariableSizeInput_;

%         Settings.deviceWriter = deviceWriter;
        % Done
        obj.AUDIO_DEVICE_READY_FLAG = true;


        % Display
        disp(' +++ Audio device connected! +++ ');
%         disp(Settings.deviceWriter);       
    end
end


