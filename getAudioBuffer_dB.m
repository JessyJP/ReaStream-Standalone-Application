function dB = getAudioBuffer_dB(signal)
% function dB = getAudioBuffer_dB(signal)
    minLevel = -100;
    if isempty(signal)
        dB = minLevel;
        return
    end
    dB = mean(20 * log10(abs(signal)));
    if dB < minLevel
        dB = minLevel;
    end
end