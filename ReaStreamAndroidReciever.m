classdef ReaStreamAndroidReciever  < handle
        
    properties (Access = public)
            % Settings and Properties
            % Connection Properties
            IP = '0.0.0.0';% Default
            Port = 58710;% Default
            TimeOut = 1;
            % UDP handle
            udp;% Connection handle
            UDP_CONNECTION_READY_FLAG = false;

            % Reastream ID tag
            ReaStreamIDtag = 'ReaperMainOut';% Default

            % Audio settings
            driverSelection = 'DirectSound';% Default
            deviceSelection = 'Default';% Default
            ByteDepth = 32/8;% Default
            bitDepthStrings = {'8-bit integer', '16-bit integer' , '24-bit integer' , '32-bit float'};
            frameStart = 'MRSR';
            startTgLen = numel('MRSR');
            SampleRate = 48000;
            % Buffer size
            pbSampSize = 128;% Default
            VariableBufferON = true;% Default
            % Buffer for debuging and testing
            DEBUG_BUFFER_REALTIME_FLAG  = true
            DEBUG_BUFFER_RECORD_FLAG    = flase;
            DEBUG_BUFFER_PLAYBACK_FLAG  = flase;            
            DEBUG_STORE_FRAME_FLAG      = false;
            FrameBuffer = [];

            % Device Writer Handle
            deviceWriter;% Device handle
            AUDIO_DEVICE_READY_FLAG = false;

            % Operation Flags ENUMERATION
            PROCESSING_ON_STATE_ = 1;% Main Processing state
            EXIT_STATE_ = 0;% Interupt flag to exit the main loop
            SKIP_FRAME_STATE_ = 2;% Flag to skip frame
            NO_TRANSMISSION_STATE_ = -1;% Flag to indicate no no transmission
            
            % It is used for UI debuging
            PacketsPerUIrefresh = 100;            
    end
    
    methods (Access = public)
        % Constructor
        function [obj] = ReaStreamAndroidReciever(myApp)
        % function [obj] = ReaStreamAndroidReciever(obj,myApp)
            % Main loop interupt
            global STATE_IN_LOOP_FLAG_;% Global interupt flag
            STATE_IN_LOOP_FLAG_ = true;
            
                if (nargin > 0) && not(isempty(myApp)) && coder.target('MATLAB')
                    % Input from interface
                    obj.IP = myApp.IPEditField.Value;
                    obj.Port = myApp.PortEditField.Value;
                    obj.ReaStreamIDtag = myApp.ReaStreamIdentifierDropDown.Value;
                    obj.driverSelection = myApp.AudioDriverDropDown.Value;
                    obj.deviceSelection = myApp.DeviceDropDown.Value;
                    obj.pbSampSize = myApp.PlaybackSampleSizeEditField.Value;
                    obj.VariableBufferON = myApp.VariableBufferCheckBox.Value;
                end

            disp(' +++ Settings Ready! +++ ');
            disp(obj);
        end
        
        % Main Method
        function [obj] = runMainProcess(obj)
%             profile on
            % Setup UPD connection
            [obj] = connectToUDP(obj);
            
            % Setup the audio device with default settings
            [obj] = obj.connectToAudioDevice();

            % Run Decode and Playback Loop
            if obj.UDP_CONNECTION_READY_FLAG && obj.AUDIO_DEVICE_READY_FLAG
                disp(' +++ Listen for Audio transmissions! +++ ');
                % profile on
                obj = decodePlaybackLoop(obj);
                % profile off
                % profile viewer
                disp(' --- Stop Listening for Audio transmissions! --- ');
            end

            % Release UDP & audio device
            obj = obj.disconnectUDP();          
            obj = obj.disconnectAudioDevice();
                        
%            profile off
%            profile viewer
        end
               
        % UDP connection methods
        function [obj] = connectToUDP(obj)
        % function [obj] = connectToUDP(obj)
            % Setup UPD connection
            if coder.target('MATLAB')  
                obj.udp = udpport(...
                    "LocalHost",obj.IP,...
                    "LocalPort",obj.Port,...
                    "EnablePortSharing",true,"Timeout",obj.TimeOut);
                disp(obj.udp);     
            end
            obj.UDP_CONNECTION_READY_FLAG = true;
            disp(' +++ UDP port opened and listening! +++ ');
        end
        
        function [obj] = disconnectUDP(obj)
            % Clear the UDP object
            if coder.target('MATLAB')
                obj.udp.delete();
            end
            disp(' --- Stop listening port! --- ');
            obj.UDP_CONNECTION_READY_FLAG = false;
        end
        
        function flushUDPbuffer(obj)
            if coder.target('MATLAB')
                obj.udp.flush();
            end
        end
        
        % Audio Device Methods
        function [obj] = connectToAudioDevice(obj)
            % Setup the audio device with default settings
            global STATE_IN_LOOP_FLAG_;
            obj.AUDIO_DEVICE_READY_FLAG = false;
            % Check and listen for Frames
            [testFrame,STATE_FLAG_NEEDED] = readReaStreameFrame(obj);
            while (STATE_FLAG_NEEDED ~= obj.PROCESSING_ON_STATE_)
                [testFrame,STATE_FLAG_NEEDED] = readReaStreameFrame(obj);
                drawnow;
                if not(STATE_IN_LOOP_FLAG_)
                    [obj] = disconnectUDP(obj);
                    return;
                end
            end

            obj.SampleRate = testFrame.SampleRate;
            % Setup Audio Device Based on the header
            obj = SetupAudioDevice(obj);

            % Check if audio device is available
            if strcmpi(obj.deviceWriter.Device,'No audio output device detected')
                disp(' --- Audio device not found!!!! --- ');
                obj = disconnectAudioDevice(obj);
                % disp(' --- Stop listening port! --- ');
                obj = obj.disconnectUDP();
                return;
            end
        end
        
        function [obj] = SetupAudioDevice(obj)
            % Setup Audio Device Based on the header
            if not(obj.AUDIO_DEVICE_READY_FLAG)

            % Setup Audio device
            obj.deviceWriter = audioDeviceWriter(...
                'Driver',obj.driverSelection,...
                'Device',obj.deviceSelection,...
                'SampleRate',obj.SampleRate,...
                'BitDepth',obj.bitDepthStrings{obj.ByteDepth},...
                'BufferSize',obj.pbSampSize,...
                'SupportVariableSizeInput',obj.VariableBufferON);

                % Display
                disp(' +++ Audio device connected! +++ ');
                disp(obj.deviceWriter);

                % Done
                obj.AUDIO_DEVICE_READY_FLAG = true;
            end
        end
        
        function [obj] = disconnectAudioDevice(obj)
            % Release the audio device
            if obj.AUDIO_DEVICE_READY_FLAG
                disp(' --- Audio device disconnected! --- ');
                release(obj.deviceWriter);
                obj.AUDIO_DEVICE_READY_FLAG = false;
            end
        end
        
    end
    
end