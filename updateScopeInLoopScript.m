% Update scope script
global myApp;
if myApp.DebugONCheckBox.Value && myApp.ScopeCheckBox.Value && myApp.scopeSetupDone_FLAG
    try
%         disp([f,size(Frame.audioFrameBuff)]);
        myApp.scope(Frame.audioFrameBuff);
    catch
        release(myApp.scope);
        myApp.scopeSetupDone_FLAG = false;
    end
end