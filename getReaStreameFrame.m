function [audioFrame,STATE_FLAG_] = getReaStreameFrame(obj)
% function [audioFrame,STATE_FLAG_,totalBytesRead] = getReaStreameFrame(obj)


audioFrame = makeFrame(...
    obj.ReaStreamIDtag,...
    obj.NumberChannels,...
    obj.SampleRate,...
    obj.deviceReader.record);



STATE_FLAG_ = obj.PROCESSING_ON_STATE_;

% %%Read and Write Entire Audio Files
% [audioData,fs] = audioread("SpeechDFT-16-8-mono-5secs.wav");
% soundsc(audioData,fs)

% %% Read and Write Audio Files Frame-by-Frame
% fileReader = dsp.AudioFileReader("Filename","SpeechDFT-16-8-mono-5secs.wav")
% deviceWriter = audioDeviceWriter("SampleRate",fileReader.SampleRate)
% 
% while ~isDone(fileReader)
%     
%     % Read one frame of audio data from the file.
%     audioData = fileReader();
%     
%     % Write one frame of audio data to your speakers.
%     deviceWriter(audioData);
%     
% end
% 
% release(fileReader)
% release(deviceWriter)

%%
% https://www.mathworks.com/help/matlab/import_export/record-and-play-audio.html