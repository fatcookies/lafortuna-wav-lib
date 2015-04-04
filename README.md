# LaFortuna WAV Library (lafortuna-wav-lib)
Play WAV audio with your LaFortuna by arp1g13! Works with RIOS!

### Dependencies
* La Fortuna (duh)
* avr-gcc
* dfu-programmer
* Working [FatFS](http://elm-chan.org/fsw/ff/00index_e.html) implementation (there's one included in this repo)
* WAV files encoded in PCM 8-bit unsigned samples at 8KHz sample rate

### How to build
* On Linux/Mac, make using the Makefile provided should work fine provided dfu-programmer is in your PATH.
* On Windows, The Makefile should compile the hex binary but the programming will probably fail so you have to do that yourself.

### How to convert audio to correct format
There are a few of options:

1. Install [sox](http://sox.sourceforge.net/), use [convert.sh](convert.sh) in a directory containing audio to convert. Windows users can adapt this easily to a batch script.
2. Use audio editing software (windows sound recorder/audacity etc) to convert audio to PCM 8-bit unsigned samples at 8KHz sample rate.


### How to use 
An example of the usage of this library is contained in [main.c in this repo](main.c)

In general:

1. Ensure clock speed is set to maximum (8 Mhz)
2. Import the header [audio.h](audio.h)
3. Start playback using audio_load(FIL* audiofile)
4. Check if playback is in progress using audio_isplaying()
5. To end playback early use audio_close()

### Known bugs
Unfortunately due to the PCM decoding implementation, the actual sample rate is 8Mhz/1024, which means around 200 samples a second are never played (even if they are loaded from the file). This introduces a slightly irritating clicking noise to the sound output which occurs twice a second, sorry about that :(

