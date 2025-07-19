# Ouroboros

Ouroboros is an instrument built for playing with feedback systems.

At it's core, it's a resonant filter, a delay, a comparator and pulse dividers arranged in a loop so that the sounds it generates create the signals it uses to modulate itself.

The default routing allows it to shift between locked, rhythmic melodies, and howling walls of noise, but with plenty of space in between to explore.

## Getting started

If you just want to start using Ouroboros and aren't yet interested in how it fits together, then the following should give you a place to start.

Audio output is the jack on the very bottom left of the panel.

Set the following controls to 12 o'clock
* All attenuverters
* Dry and Wet output controls
* Delay Time and Input
* Stability and Rate
* Frequency
* Noise mix input

Set the following controls to the minimum
* Wet and Clock mix input
* VCA Level
* Feedback

Set the resonance to not quite the maximum.

You should now have sound being created.

Play with the Stability and Rate controls to get things moving at the speed you want.

## How it works

Whilst ultimately it's the combination of all of the parts interacting that makes things interesting, it's helpful to understand each of them separately to get an idea of what everything is doing.

### Filter

The filter is a fairly standard state-variable, 12db per-octave design built around the 2164 gain cell chip. The cut-off frequency and resonance are voltage controllable with attenuverters on both.

There's also a dedicated ping input which is the primary sound generator when nothing else is patched.

The band pass output of this is what feeds the delay, whilst the low-pass and high-pass outputs, as well as volt-per-octave control and a direct input are available via the expansion module that connects to a header on the back.

### Delay

The delay is built around the well known PT2399 IC which gives a good range of times, gradually disintegrating into clicks and noise as they get longer. Delay times are voltage controllable with an attenuverter.

On the input, as the control increases past 12 o'clock, soft-clipping distortion will be added to the signal. The output has separate Wet and Dry controls which feed the final mix, as well as a feedback control which will let the whole thing self oscillate, and add in soft-clipping distortion as well.

One interesting thing to node, is that as well as a Wet output jack, there is also a Clock output, which gives the 0-5 volt square wave oscillator that is derived from the digital clock in the chip. The frequency of this will change along with the delay time.

### VCA

The VCA is a simple, linear VCA that is normalled to take the Dry/Wet mix output from the delay and feed it back to the input of the filter. The level CV has an attenuverter and it's DC-coupled so can be used to modulate CV itself.

### Mixer and Comparator

The delay Wet and Clock signals are combined with a Noise source with the mixed signal being fed into a comparator. This is used to generate squared pulses from any signal fed into it. The Stability control is used to set the threshold for the comparator and helps to give some control over how much it will trigger.

### Clock Divider

The signal output from the Comparator is sent to a variable divider which can divide by any value from 1 to 128. This slower signal then feeds further clock dividers which divide by 2, 3, 4, 5, 6, 7 and 8.
