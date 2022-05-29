classdef ReaStreamTransmitter  < ReaStreamReceiver
        
    properties (Access = public)
            % Settings and Properties
            % Connection Properties
            TransmitterIP = 'localhost';% Default

            % UDP handle
            TransmitterUDP;% Connection handle
    
    end
    
    methods (Access = public)

                % Main Method
        function [obj] = runMainTransmissionProcess(obj)
%             profile on
            % Setup UPD connection
            [obj] = connectReceiverUDP(obj);
            
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
            obj = obj.disconnectReceiverUDP();          
            obj = obj.disconnectAudioDevice();
                        
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
        
        function flushUDPtransmissionQueue(obj)
            if coder.target('MATLAB')
                obj.TransmitterUDP.flush();
            end
        end
        

        
    end
    
end
