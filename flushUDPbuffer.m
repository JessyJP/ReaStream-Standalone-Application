function flushUDPbuffer(obj)
    if coder.target('MATLAB')
        obj.ReceiverUDP.flush();
    end
	disp('UDP buffer flushed!');
end