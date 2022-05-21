function [byteArrayOUT] = readUDPbuffer(obj,byteSize,type)
% function [byteArrayOUT] = readUDPbuffer(obj,byteSize,type)
    % Global Declaration FOR RECORD AND PLAYBACK
    global GlobalByteBuffer_    Gi_  Ri_   STATE_IN_LOOP_FLAG_;    

    %% The actual code needed
    if  obj.DEBUG_BUFFER_REALTIME_FLAG
        
        [byteArrayOUT] = obj.ReceiverUDP.read(byteSize,type);
%     [byteArrayOUT] = read(obj.ReceiverUDP,byteSize,type); 

    end
    
    %% For testing
    % FOR TESTING for recording data

    if obj.DEBUG_BUFFER_RECORD_FLAG 
        switch (type) 
            case 'uint8'
                byteArrayREC = typecast(uint8(byteArrayOUT),'uint8');
            case 'single'
                byteArrayREC = typecast(single(byteArrayOUT),'uint8');
            otherwise
                error('tppe not supported');
        end
        
        if isempty(GlobalByteBuffer_)
            GlobalByteBuffer_ = byteArrayREC;
        else
            if not(isempty(Ri_))
              GlobalByteBuffer_(Ri_+[1:numel(byteArrayREC)]) = byteArrayREC;
              Ri_ = Ri_ + numel(byteArrayREC);
            else
              GlobalByteBuffer_ = [GlobalByteBuffer_ , byteArrayREC];
            end
        end
    end
    
    % For reading back data 
    if obj.DEBUG_BUFFER_PLAYBACK_FLAG
        
        if isempty(GlobalByteBuffer_)
            Gi_ = 0;
            filename = 'UDPdataForTesting.mat';
            data = load(filename,'GlobalByteBuffer_');
            GlobalByteBuffer_ = data.GlobalByteBuffer_;
        end
        if Gi_+byteSize > numel(GlobalByteBuffer_)
            % Reset
            Gi_ =0;
            % Exit
            STATE_IN_LOOP_FLAG_ = false;
        end
        
        switch (type) 
            case 'uint8'
                byteArrayOUT = typecast(uint8(GlobalByteBuffer_(Gi_+[1:byteSize])),'uint8');
                Gi_ = Gi_ + byteSize;
            case 'single'
                byteArrayOUT = typecast(uint8(GlobalByteBuffer_(Gi_+[1:byteSize*4])),'single');
                Gi_ = Gi_ + byteSize*4;
            otherwise
                error('tppe not supported');
        end
        
    end
end