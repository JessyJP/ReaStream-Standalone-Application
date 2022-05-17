function onKeyboardPressCallback(figH,eventdata)
    % Unpack
    global STATE_IN_LOOP_FLAG_;
    obj = figH.UserData;
    % Check for exit flag
    if strcmpi(eventdata.Key,'escape')
        STATE_IN_LOOP_FLAG_ = obj.EXIT_STATE_;   
        if strcmpi(figH.Name,'MATLAB App')
            connectionSwitch = findobj(figH.Children,'type','uiswitch');
            connectionSwitch.Value = 'Off';
        else
            close(figH)
        end
    end
end