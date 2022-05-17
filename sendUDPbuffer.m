function [output] = sendUDPbuffer(obj,byteArray)
% function [output] = sendUDPbuffer(obj,bTransmitteryteSize,type)


%     if  obj.DEBUG_BUFFER_REALTIME_FLAG
        
        [output] = obj.TransmitterUDP.write(byteArray);
%     [output] = read(obj.ReceiverUDP,byteSize,type); 

%     end
    