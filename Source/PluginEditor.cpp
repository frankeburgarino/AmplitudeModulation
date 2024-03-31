/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
AmplitudeModulationAudioProcessorEditor::AmplitudeModulationAudioProcessorEditor (AmplitudeModulationAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
{
    setSize(400, 300);

    addAndMakeVisible(frequencySlider);
    frequencySlider.setSliderStyle(juce::Slider::SliderStyle::RotaryHorizontalVerticalDrag);
    frequencySlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 50, 25);
    frequencySlider.setRange(0.1f, 10.f, .01f);
    //frequencySlider.setSkewFactorFromMidPoint(10.f);
    frequencySlider.setColour(juce::Slider::ColourIds::trackColourId, juce::Colours::whitesmoke);
    frequencySlider.setDoubleClickReturnValue(true, 1.0);
    frequencySlider.addListener(this);

    addAndMakeVisible(frequencyLabel);
    frequencyLabel.setText("Frequency", juce::dontSendNotification);
    //frequencyLabel.attachToComponent(&frequencySlider, false);
    frequencyLabel.setJustificationType(juce::Justification::centred);

    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    
}

AmplitudeModulationAudioProcessorEditor::~AmplitudeModulationAudioProcessorEditor()
{
}

//==============================================================================
void AmplitudeModulationAudioProcessorEditor::paint (juce::Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (juce::ResizableWindow::backgroundColourId));

    g.setColour (juce::Colours::white);
    g.setFont (25.0f);
    g.drawFittedText("AmplitudeModulation", getLocalBounds(), juce::Justification::centredTop, 1);
}

void AmplitudeModulationAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    auto topMargin = 30;

    frequencySlider.setBounds(100, 50, 200, 200);
    frequencyLabel.setBounds(150, 250, 100, 25);

}

void AmplitudeModulationAudioProcessorEditor::sliderValueChanged(juce::Slider* slider) {
    audioProcessor.frequency = frequencySlider.getValue();
}
