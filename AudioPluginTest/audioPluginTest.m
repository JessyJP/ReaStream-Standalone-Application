%%  Load plugin
clear; close all; clc;
% pluginPath = "c:\Program Files\Steinberg\VSTPlugins\UJAM\VD-SOLID.dll" ;
pluginPath = "c:\Program Files\VstPlugIns\ReaPlugs\reastream-standalone.dll";
hostedPlugin = loadAudioPlugin(pluginPath);

%% Setup Plugin
clc;
hostedPlugin.DisplayMode ="Parameters";

disp(info(hostedPlugin));
dispParameter(hostedPlugin)
disp('==================================');
hostedPlugin.resv = 0;

disp('==================================');
disp(info(hostedPlugin));
dispParameter(hostedPlugin)
%% Run Plugin
close all;
in = [0 0 ; 0 0];
plt = plot(in );
legend L R;
% while true 
%     out = hostedPlugin.process(in);
    
%     drawnow;
% end

%% Get UDP data
clc; clear all;
ip='LocalHost';
ip='127.0.0.1';
port=58710;

ip='LocalHost';
% ip='127.0.0.1';
udpr = dsp.UDPReceiver('LocalIPPort',port);
udps = dsp.UDPSender('RemoteIPPort',port);

setup(udpr); 

bytesSent = 0;
bytesReceived = 0;
dataLength = 128;

for k = 1:20
   dataSent = uint8(255*rand(1,dataLength));
   bytesSent = bytesSent + dataLength;
   udps(dataSent);
   dataReceived = udpr();
   bytesReceived = bytesReceived + length(dataReceived);
end

release(udps);
release(udpr);

fprintf('Bytes sent:     %d\n', bytesSent);
%%
% [r.s]=system('netstat');
clc; clear all;
ip='LocalHost';
% ip='127.0.0.1';
port=58710;
u=udp(ip,port) 
%define the sender port as programed in arduino or any other device
fopen(u)
try
    disp('===')
fscanf(u)
    disp('===')
end
fclose(u)