/*
 * https://github.com/fatcookies
 * 
 * La Fortuna (at90usb1286) @ 8MHz
 * Audio test
 * 
 * Adapted from:
 * http://avrpcm.blogspot.co.uk/2010/11/playing-8-bit-pcm-using-any-avr.html 
 */

#include "audio.h"
#include <avr/io.h>

int main(void) {
	/* 8MHz clock, no prescaling (DS, p. 48) */
    CLKPR = (1 << CLKPCE);
    CLKPR = 0;
	
	FATFS FatFs;
	FIL File;
	f_mount(&FatFs, "", 0);
	f_open(&File,"audio.wav",FA_READ);
	
	audio_load(&File);
	for(;;);
}
