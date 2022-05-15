function [output] = readUDPbuffer(obj,byteSize,type)
% function [output] = readUDPbuffer(obj,byteSize,type)
    % Global Declaration FOR RECORD AND PLAYBACK
    global output_ i STATE_IN_LOOP_FLAG_;    

    %% The actual code needed
    if  obj.DEBUG_BUFFER_REALTIME_FLAG
        
        [output] = obj.udp.read(byteSize,type);
%     [output] = read(obj.udp,byteSize,type); 

    end
    
    %% For testing
    % FOR TESTING for recording data

    if obj.DEBUG_BUFFER_RECORD_FLAG 
        switch (type) 
            case 'uint8'
                outputRec = typecast(uint8(output),'uint8');
            case 'single'
                outputRec = typecast(single(output),'uint8');
            otherwise
                error('tppe not supported');
        end
        
        if isempty(output_)
            output_ = outputRec;
        else
            output_ = [output_ , outputRec];
        end
    end
    
    % For reading back data 
    if obj.DEBUG_BUFFER_PLAYBACK_FLAG
        
        if isempty(output_)
            i = 0;
            filename = 'UDPdataForTesting.mat';
            data = load(filename,'output_');
            output_ = data.output_;
        end
        if i+byteSize > numel(output_)
            i =0;
            
            STATE_IN_LOOP_FLAG_ = false;
        end
        
        switch (type) 
            case 'uint8'
                output = typecast(uint8(output_(i+[1:byteSize])),'uint8');
            case 'single'
                output = typecast(uint8(output_(i+[1:byteSize*4])),'single');
            otherwise
                error('tppe not supported');
        end
        i = i + byteSize;
    end
end