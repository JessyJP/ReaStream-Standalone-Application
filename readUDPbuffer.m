function [output] = readUDPbuffer(obj,byteSize,type)
% function [output] = readUDPbuffer(obj,byteSize,type)
    % Global Declaration FOR RECORD AND PLAYBACK
    global output_ i STATE_IN_LOOP_FLAG_;    
    REAL_TIME_ = coder.target('MATLAB');
    RECORD_ = 0;
    PLAYBACK_ = not(coder.target('MATLAB'));

    %% The actual code needed
    if  REAL_TIME_
        
        [output] = obj.udp.read(byteSize,type);
%     [output] = read(obj.udp,byteSize,type); 

    end
    
    %% For testing
    % FOR TESTING for recording data

    if RECORD_ 
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
    if PLAYBACK_
        
        if isempty(output_)
            i = 0;
            filename = 'UDPdataForTesting.mat';
            data = load(filename,'output_');
            output_ = data.output_;
        end
        if i+byteSize > 0.2*numel(output_)
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