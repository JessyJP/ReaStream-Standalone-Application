classdef ReaStreamTransmitter  < handle
        
    properties (Access = public)
            % Settings and Properties
            % Connection Properties
            TransmitterIP = '0.0.0.0';% Default
            Port = 58710;% Default
            TimeOut = 1;
            % UDP handle
            TransmitterUDP;% Connection handle
            UDP_CONNECTION_READY_FLAG = false;

            % Reastream ID tag
            ReaStreamIDtag = 'ReaperMainOut';% Default

            % Audio settings
            driverSelection = 'DirectSound';% Default % TODO
            deviceSelection = 'Default';% Default % TODO
            ByteDepth = 32/8;% Default
            bitDepthStrings = {'8-bit integer', '16-bit integer' , '24-bit integer' , '32-bit float'};
            frameStart = 'MRSR';
            startTgLen = numel('MRSR');
            SampleRate = 48000;
            NumberChannels = 1;
            OutputDataType = "single"

            % Buffer size
            pbSampSize = 128;% Default
            VariableBufferON = true;% Default
            % Buffer for debuging and testing
            DEBUG_ACTIVEKEYBOARD_INTERRUPT_FLAG = true
            DEBUG_BUFFER_REALTIME_FLAG  = true
            DEBUG_BUFFER_RECORD_FLAG    = false;
            DEBUG_BUFFER_PLAYBACK_FLAG  = false;            
            DEBUG_STORE_FRAME_FLAG      = false;
            DEBUG_SCOPE_SHOW_FLAG       = false;  
            FrameBuffer = [];

            % Device Writer Handle
            deviceReader;% Device handle
            AUDIO_DEVICE_READY_FLAG = false;

            % Operation Flags ENUMERATION
            PROCESSING_ON_STATE_ = 1;% Main Processing state
            EXIT_STATE_ = 0;% Interupt flag to exit the main loop
            SKIP_FRAME_STATE_ = 2;% Flag to skip frameconnectToInputAudioDevice
            NO_TRANSMISSION_STATE_ = -1;% Flag to indicate no no transmission
            
            % It is used for UI debuging
            PacketsPerUIrefresh = 100;            
    end
    
    methods (Access = public)
        % Constructor
        function [obj] = ReaStreamTransmitter(myApp)
        % function [obj] = ReaStreamTransmitter(obj,myApp)
            % Main loop interupt
            global STATE_IN_LOOP_FLAG_;% Global interupt flag
            STATE_IN_LOOP_FLAG_ = true;
            
                if (nargin > 0) && not(isempty(myApp)) && coder.target('MATLAB')
                    % Input from interface
                    obj.TransmitterIP = myApp.TransmitterIPEditField.Value;
                    obj.Port = myApp.TransmitterPortEditField.Value;
                    obj.ReaStreamIDtag = myApp.ReaStreamIdentifierDropDown.Value;
                    obj.driverSelection = myApp.AudioDriverDropDown.Value;
                    obj.deviceSelection = myApp.DeviceDropDown.Value;
                    obj.pbSampSize = myApp.PlaybackSampleSizeEditField.Value;
%                     obj.VariableBufferON = myApp.VariableBufferCheckBox.Value;
                end

            disp(' +++ Settings Ready! +++ ');
            disp(obj);
        end
        
        % Main Method
        function [obj] = runMainReceptionProcess(obj)
%             profile on

            % Setup the audio device with default settings
            [obj] = obj.connectToInputAudioDevice();

            % Setup UPD connection
            [obj] = connectTransmitterUDP(obj);
            


            % Run Decode and Playback Loop
            if obj.UDP_CONNECTION_READY_FLAG && obj.AUDIO_DEVICE_READY_FLAG
                disp(' +++ Send Audio transmissions! +++ ');
                % profile on
                obj = encodeRecordingLoop(obj);
                % profile off
                % profile viewer
                disp(' --- Stop Sedning Audio transmissions! --- ');
            end

            % Release UDP & audio device
            obj = obj.disconnectInputAudioDevice();
            obj = obj.disconnectTransmitterUDP();          
            
                        
%            profile off
%            profile viewer
        end
        
               
        % UDP connection methods
        function [obj] = connectTransmitterUDP(obj)
        % function [obj] = connectTransmitterUDP(obj)
            % Setup UPD connection
            if coder.target('MATLAB')  
                obj.TransmitterUDP = udpport(...
                    "LocalHost",obj.TransmitterIP,...
                    "LocalPort",obj.Port,...
                    "EnablePortSharing",true,"Timeout",obj.TimeOut);
                disp(obj.TransmitterUDP);     
            end
            obj.UDP_CONNECTION_READY_FLAG = true;
            disp(' +++ Open UDP transmission socket! +++ ');
        end
        
        function [obj] = disconnectTransmitterUDP(obj)
            % Clear the UDP object
            if coder.target('MATLAB')
                obj.TransmitterUDP.delete();
            end
            disp(' --- Stop transmission socket! --- ');
            obj.UDP_CONNECTION_READY_FLAG = false;
        end
        
        function flushUDPbuffer(obj)
            if coder.target('MATLAB')
                obj.TransmitterUDP.flush();
            end
        end
        
        % Audio Device Methods
        function [obj] = connectToInputAudioDevice(obj)
            % Setup the audio device with default settings
            global STATE_IN_LOOP_FLAG_;
            obj.AUDIO_DEVICE_READY_FLAG = false;

            % Setup Audio Device Based on the header
            obj = SetupInputAudioDevice(obj);


            % Check if audio device is available
            if strcmpi(obj.deviceReader.Device,'No audio device detected')
                disp(' --- Audio device not found!!!! --- ');
                obj = disconnectInputAudioDevice(obj);
                % disp(' --- Stop listening port! --- ');
                obj = obj.disconnectTransmitterUDP();
                return;
            end
            
            % Check and listen for Frames
            [testFrame,STATE_FLAG_NEEDED] = getReaStreameFrame(obj);
            while (STATE_FLAG_NEEDED ~= obj.PROCESSING_ON_STATE_)
                [testFrame,STATE_FLAG_NEEDED] = readReaStreameFrame(obj);
                drawnow;
                if not(STATE_IN_LOOP_FLAG_)
                    [obj] = disconnectTransmitterUDP(obj);
                    return;
                end
            end

        end
        
        function [obj] = SetupInputAudioDevice(obj)
            % Setup Audio Device Based on the header
            if not(obj.AUDIO_DEVICE_READY_FLAG)

            % Setup Audio device
            obj.deviceReader = audioDeviceReader(...
                'Driver',obj.driverSelection,...
                'Device',obj.deviceSelection,...
                'SampleRate',obj.SampleRate,...
                'BitDepth',obj.bitDepthStrings{obj.ByteDepth},...
                'NumChannels',obj.NumberChannels,...
                'OutputDataType',obj.OutputDataType);

                % Display
                disp(' +++ Audio device connected! +++ ');
                disp(obj.deviceReader);

                % Done
                obj.AUDIO_DEVICE_READY_FLAG = true;
            end
        end
        
        function [obj] = disconnectInputAudioDevice(obj)
            % Release the audio device
            if obj.AUDIO_DEVICE_READY_FLAG
                disp(' --- Audio device disconnected! --- ');
                release(obj.deviceReader);
                obj.AUDIO_DEVICE_READY_FLAG = false;
            end
        end
        
    end
    
end
