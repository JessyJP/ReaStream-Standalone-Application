classdef ReaStreamTransmitter  < ReaStreamReceiver
        
    properties (Access = public)
            % Settings and Properties
            % Connection Properties
            TransmitterIP = '0.0.0.0';% Default

            % UDP handle
            TransmitterUDP;% Connection handle
    
    end
    
    methods (Access = public)
        

               
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
            disp(' +++ UDP port opened and listening! +++ ');
        end
        
        function [obj] = disconnectTransmitterUDP(obj)
            % Clear the UDP object
            if coder.target('MATLAB')
                obj.TransmitterUDP.delete();
            end
            disp(' --- Stop listening port! --- ');
            obj.UDP_CONNECTION_READY_FLAG = false;
        end
        
        function flushUDPtransmissionQueue(obj)
            if coder.target('MATLAB')
                obj.TransmitterUDP.flush();
            end
        end
        

        
    end
    
end
