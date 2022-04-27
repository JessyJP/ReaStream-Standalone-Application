function flushUDPbuffer(obj)
    if coder.target('MATLAB')
        obj.udp.flush();
    end
	disp('UDP buffer flushed!');
end