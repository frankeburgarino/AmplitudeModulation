/*
  ==============================================================================

    AmplitudeModulation.h
    Created: 29 Feb 2024 12:42:13pm
    Author:  ant3b

  ==============================================================================
*/

#pragma once

//#import <JuceHeader.h>
#include <JuceHeader.h>

#define _USE_MATH_DEFINES
#include <math.h>
#include <cmath>


class AmplitudeModulation {

public:

    void prepareToPlay(double sampleRate);

    float processSample(float x, int channel);

    void process(float* buffer, int numSamples, int channel);

    void setFrequency(float freq);

private:

    float Fs = 1.f;
    float currentAngle[2] = { 0.f };
    float angleChange = 1.f;

    float freqHz = 1.f;

    void setAngleChange();

    const float PIx2 = 2.f * M_PI;

};