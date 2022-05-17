function [output] = sendUDPbuffer(obj,byteArray)
% function [output] = sendUDPbuffer(obj,bTransmitteryteSize,type)


%     if  obj.DEBUG_BUFFER_REALTIME_FLAG
        try 
%             obj.TransmitterUDP.write(byteArray,"uint8");
            obj.TransmitterUDP.write(byteArray,"uint8");
        catch
            obj.TransmitterUDP.write(byteArray,"uint8",...
                obj.TransmitterUDP.LocalHost,obj.TransmitterUDP.LocalPort);
        end
%     [output] = write(obj.ReceiverUDP,byteSize,type); 

%     end
    