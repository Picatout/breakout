/*
 * keys.c
 *
 *  Created on: 2018-01-09
 *      Author: Jacques
 */

#include "keypad.h"
#include "chip8.h"

// read keypad, debounced.
// the keypad state must be stable for DEBOUNCE_DLY.
unsigned char keypad_read(){
	char count=0;
	char kp,nkp;

#define DEBOUNCE_DLY (10)

	kp = ~(0xc0+((P0&0x60)>>1)+(P1&0xf));
	do{
		nkp=~(0xc0+((P0&0x60)>>1)+(P1&0xf));
	    if (nkp==kp){
	    	count++;
	    }else{
	    	count=0;
	    	kp=nkp;
	    }
	    pause(1);
	}while (count<DEBOUNCE_DLY);
	return kp;
}

// wait for any key pressed.
unsigned char wait_key(){
	unsigned char key;
	while ((key=keypad_read())==KEY_NONE);
	return key;
}

// return 1 if key is down else return 0
unsigned char key_down(uint8_t key){
	char k;
	k= keypad_read();
	return k & key;
}
