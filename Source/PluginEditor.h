/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"

//==============================================================================
/**
*/
class AmplitudeModulationAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Slider::Listener
{
public:
    AmplitudeModulationAudioProcessorEditor (AmplitudeModulationAudioProcessor&);
    ~AmplitudeModulationAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

    void sliderValueChanged(juce::Slider* slider) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.

    AmplitudeModulationAudioProcessor& audioProcessor;

    juce::Slider frequencySlider;
    juce::Label frequencyLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (AmplitudeModulationAudioProcessorEditor)
};
