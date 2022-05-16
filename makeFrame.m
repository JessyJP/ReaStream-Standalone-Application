function [S] = makeFrame(ReaStreamLabel,numChannels,SampleRate,audioBuffer)
% function [S] = makeFrame(ReaStreamLabel,numChannels,SampleRate,audioBuffer)

    S = rsFrameHeader2Struct([]);
        S.streamName     = ReaStreamLabel;
        S.numChannels    = numChannels;
        S.SampleRate     = SampleRate;
        S.audioFrameBuff = single(audioBuffer);

        % Validate
        S.bufferSize       = numel(S.audioFrameBuff);
        S.audioByteLength  = S.bufferSize*4;
        S.udpPayLoadBytes  = S.audioByteLength+47;
        S.timeLength_ms    = S.SampleRate/S.bufferSize;
end