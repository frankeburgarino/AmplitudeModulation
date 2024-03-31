/*
  ==============================================================================

    AmplitudeModulation.cpp
    Created: 29 Feb 2024 12:42:13pm
    Author:  ant3b

  ==============================================================================
*/

#include "AmplitudeModulation.h"

void AmplitudeModulation::prepareToPlay(double sampleRate) {
    if (Fs != sampleRate) {
        Fs = (float)sampleRate;
        setAngleChange();
    }
}

void AmplitudeModulation::process(float* buffer, int numSamples, int channel) {

    for (int n = 0; n < numSamples; n++) {
        float x = buffer[n];
        buffer[n] = processSample(x, channel);
    }

}

float AmplitudeModulation::processSample(float x, int channel)
{
    float y = x * (((std::sin(currentAngle[channel])) + 1) / 2);

    currentAngle[channel] += angleChange;

    if (currentAngle[channel] > PIx2) {
        currentAngle[channel] -= PIx2;
    }

    return y;
}

void AmplitudeModulation::setFrequency(float freq) {
    freqHz = freq;
    setAngleChange();
}

void AmplitudeModulation::setAngleChange() {

    angleChange = freqHz * PIx2 / Fs;

}