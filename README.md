# LaFortuna WAV Library (lafortuna-wav-lib)
Play WAV audio with your LaFortuna by arp1g13! Works with RIOS!

### Dependencies
* La Fortuna (duh)
* avr-gcc
* dfu-programmer
* Working [FatFS](http://elm-chan.org/fsw/ff/00index_e.html) implementation (there's one included in this repo)
* WAV files encoded in mono PCM 8-bit unsigned samples at 16KHz sample rate OR stereo at 8KHz sample rate

### How to build
* On Linux/Mac, make using the Makefile provided should work fine provided dfu-programmer is in your PATH.
* On Windows, The Makefile should compile the hex binary but the programming will probably fail so you have to do that yourself.

### How to convert audio to correct format
There are a few of options:

1. Install [sox](http://sox.sourceforge.net/) for options 2 and 3

2. Use [mono.sh](mono.sh) in a directory containing audio to convert the sound to a mono recording with the highest quality (16KHz sample rate). Windows users can adapt this easily to a batch script.

2. Use [stereo.sh](stereo.sh) in a directory containg audtio to convert the sound to a STEREO recording with an 8KHz sample rate.

3. Use audio editing software (windows sound recorder/audacity etc) to convert audio to unsigned 8 bit PCM at a sample rate of either 8kHz for stereo or 16kHz for mono.

4. EXPERIMENTAL: If you modify the bash scripts above you could attempt to encode audio at 32000 samples/sec in one channel (mono) or 16000 samples/sec in two channels (stereo). The LaFortuna should be able to play this audio but audio artifacts may be apparant.


### How to use 
An example of the usage of this library is contained in [main.c in this repo](main.c)

In general:

1. Ensure clock speed is set to maximum (8 Mhz)
2. Import the header [audio.h](audio.h)
3. Start playback using audio_load(FIL* audiofile)
4. Check if playback is in progress using audio_isplaying()
5. To end playback early use audio_close()

