global DEBUG_ON_LAST_STATE_FLAG_ myApp;

% UI dB meter
myApp.Gauge_L.Value = getAudioBuffer_dB(Frame.audioFrameBuff(:,1));
if size(Frame.audioFrameBuff,2) > 1
myApp.Gauge_R.Value = getAudioBuffer_dB(Frame.audioFrameBuff(:,1));
end

% obj = obj;
% Debug    
if myApp.DebugONCheckBox.Value ~= DEBUG_ON_LAST_STATE_FLAG_
    if myApp.DebugONCheckBox.Value
    %Switch on visibility  
        for ff = 1:numel(myApp.debugFields)
            myApp.(myApp.debugFields{ff}).Visible = true;
        end
    else
        for ff = 1:numel(myApp.debugFields)
            myApp.(myApp.debugFields{ff}).Visible = false;
        end
    end
    drawnow;
end
DEBUG_ON_LAST_STATE_FLAG_ = myApp.DebugONCheckBox.Value;


if myApp.DebugONCheckBox.Value
        %% Debug Settings
        % obj.ReceiverUDP Diagnostics
        
        % Statistics for debugin
        myApp.MeanNumBytesAvailableTextArea.Value=num2str(round(mean(myApp.UPD_bufferSizes)));
        myApp.UPD_bufferSizes = [myApp.UPD_bufferSizes(2:end);obj.ReceiverUDP.NumBytesAvailable];
        
        
        if myApp.ScopeCheckBox.Value && ...
         ( not(myApp.scopeSetupDone_FLAG) || (myApp.scopeSetupDone_FLAG) && not(isvalid(myApp.scope)) )

            myApp.scope = timescope( ...
            'SampleRate',obj.SampleRate, ...
            'TimeSpanSource','property',...
            'TimeSpan',2, ...
            'BufferLength',obj.SampleRate*2*2, ...
            'YLimits',[-1,1], ...
            'TimeSpanOverrunAction',"Scroll");
            
            % The flag is needed because its a hassle to do to many checks
            % for an empty int that is not a handle 
            myApp.scopeSetupDone_FLAG = true;
            drawnow;
            pause(0.1);
            flushUDPbuffer(obj);
        end  
        
        if myApp.udpBufferSizeCheckBox.Value
            %% Plotting
            if (mod(f,myApp.FPSEditField.Value) == 0)     
                if not(~isempty(myApp.ax) && isvalid(myApp.ax))
                    %% Initialize for plotting
                    fig = figure;
                    plt = plot(myApp.UPD_bufferSizes);
                    myApp.ax = plt.Parent;
                end
                % Plot
                plot(myApp.ax,myApp.UPD_bufferSizes);
                title(myApp.ax,['Mean(NumBytesAvailable)=',num2str(round(mean(myApp.UPD_bufferSizes)))]);
                drawnow;
            end
        end
%         PT(f) = (1000*toc);

    end