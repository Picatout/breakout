/*
 * chip8.c
 *
 *  Created on: 2018-01-03
 *      Author: Jacques
 */

#include <stdlib.h>
#include <string.h>
#include <SI_EFM8BB1_Register_Enums.h>                  // SFR declarations
#include "InitDevice.h"
#include "chip8.h"



unsigned char xdata video[256];

char code digits[30]={
   0xea,0xaa,0xe0, // 0
   0x4c,0x44,0xe0, // 1
   0xe2,0xe8,0xe0, // 2
   0xe2,0xe2,0xe0, // 3
   0xaa,0xe2,0x20, // 4
   0xe8,0xe2,0xe0, // 5
   0x88,0xea,0xe0, // 6
   0xe2,0x22,0x20, // 7
   0xea,0xea,0xe0, // 8
   0xea,0xe2,0x20  // 9
};

//static t_vm vm_state;
//static unsigned char vm_data[DATA_SIZE];

void clr_scr(){
	memset(video,0,HBYTES*VRES);
}
// scroll down 1-31 lines
void scroll_down(char lines){
	if (!lines) return;
	lines &=0x1f;
	memmove(video+HBYTES*lines,video,HBYTES*VRES-HBYTES*lines);
	memset(video,0,HBYTES*lines);
}

// scroll up 1..31 lines
void scroll_up(char lines){
	if (!lines) return;
	lines &=0x1f;
	memmove(video,video+HBYTES*lines,HBYTES*VRES-HBYTES*lines);
	memset(video+HBYTES*VRES-HBYTES*lines,0,HBYTES*lines);
}

// scroll left 1 pixel
void scroll_left(){
	char row,col,ofs;
	for (row=0;row<VRES;row++){
		ofs=row*HBYTES;
		for (col=0;col<(HBYTES-1);col++){
			video[ofs]<<=1;
			video[ofs]|=video[ofs+1]>>7;
			ofs++;
		}
		video[ofs]<<=1;
	}
}

// scroll right 1 pixel
void scroll_right(){
	char row,col,ofs;
	for (row=0;row<VRES;row++){
		ofs=row*HBYTES+HBYTES-1;
		for (col=HBYTES-1;col;col--){
			video[ofs]>>=1;
			video[ofs]|=video[ofs-1]<<7;
			ofs--;
		}
		video[ofs]>>=1;
	}
}

char xor_pixel(char x, char y){
	int i;
	char mask;

	mask=1<<(7-x%8);
	i=y*8+x/8;
	video[i]^=mask;
	return !(video[i]&mask);
}

char draw_sprite(char x, char y, char width,char height, char* sprite){
	char h,w,collision;

	collision=0;
	for (h=0;h<height;h++)
		for (w=0;w<width;w++){
			if (sprite[h]&((1<<(7-w)))){
				collision|=xor_pixel(x+w,y+h);
			}
		}
	return collision;
}

void draw_digit(char x, char y, char digit){
	char row,ofs,nibble[1];

	digit %= 10;
	ofs = digit*3;
	for (row=0;row<5;row++){
		if (row&1){
			nibble[0]=digits[ofs+(row>>1)]<<4;
		}else{
			nibble[0]=digits[ofs+(row>>1)];
		}
		draw_sprite(x,y,4,1,nibble);
		y++;
	}
}

void print_int(char x, char y, unsigned int u){
	char r,modulo;

	for (r=x+16;r>=x;r-=4){
		modulo=u%10;
		draw_digit(r,y,modulo);
		u/=10;
		if (!u)break;
	}
}


#define MS 65012
// pause in milliseconds
void pause(unsigned int msec){
	TL1=MS&0xff;
	TH1=MS>>8;
	TCON_TF1=0;
	TMOD|=1<<TMOD_T1M__SHIFT;
	TCON_TR1=1;
	while (msec){
		while (!TCON_TF1);
		msec--;
		TL1=MS&0xff;
		TH1=MS>>8;
		TCON_TF1=0;
	}
	TCON_TR1=0;
}

char rand_bit(){
	ADC0CN0_ADINT=0;
	ADC0CN0_ADEN=1;
	ADC0CN0_ADBUSY=1;
	while (!ADC0CN0_ADINT);
	ADC0CN0_ADEN=0;
	return ADC0L&1;
}

unsigned random(char n){
	unsigned r=0;

	for (;n;n--){
		r<<=1;
		r+=rand_bit();
	}
	return r;
}

#define _tmr0_on(r) { TL0=r&255;\
	                TH0=r>>8;\
	                TCON_TF1=0;\
	                TCON_TR0=1;}

#define _tmr0_off() {TCON_TR0=0;P0_B7=0;}

// generate noise for milliseconds
void noise(unsigned char msec){
	TL1=MS&0xff;
	TH1=MS>>8;
	TCON&=~TCON_TF1__BMASK;
//	TMOD|=1<<TMOD_T1M__SHIFT;
	TCON|=TCON_TR1__BMASK;
	while (msec){
		P0_B7=rand_bit();
		if (TCON&TCON_TF1__BMASK){
			TL1=MS&0xff;
			TH1=MS>>8;
			TCON&=~TCON_TF1__BMASK;
			msec--;
		}
	}
	TCON&=~TCON_TR1__BMASK;
	P0_B7=0;
}

unsigned int tmr_reload;
void sound_fx(unsigned char snd, unsigned char msec){
#define FR_500 (65005)
#define FR_750 (65196)
#define FR_5245 (65486)

	char phase;

	_tmr0_on(FR_5245);
	switch (snd){
	case BEEP:
		tmr_reload=FR_500;
        pause(msec);
		break;
	case UP_SWEEP:
		tmr_reload=FR_500;
		phase=50;
		while (msec){
			tmr_reload+=phase;
			if (tmr_reload<FR_500){
				tmr_reload=FR_500;
			}
			pause(5);
			if (msec>5) msec-=5;else msec=0;
		}
		break;
	case WARBLE:
		tmr_reload=FR_500;
		phase=0;
		while (msec){
			pause(5);
			if (msec>5) msec-=5;else msec=0;
			if (!phase) tmr_reload=FR_750;
			else tmr_reload=FR_500;
			phase=1-phase;
		}
		break;
	case DOWN_SWEEP:
		tmr_reload=FR_5245;
		phase=50;
		while (msec){
			tmr_reload-=phase;
			if (tmr_reload<FR_500){
				tmr_reload=FR_5245;
			}
			pause(5);
			if (msec>5) msec-=5;else msec=0;
		}
		break;
	case TRIANGLE_SWEEP:
		tmr_reload=FR_500;
		phase=50;
		while (msec){
			pause(5);
			tmr_reload+=phase;
			if (tmr_reload<FR_500){
				phase=-phase;
				tmr_reload+=phase;
			}
			if (msec>5)msec-=5;else msec=0;
		}
		break;
	}//switch
	_tmr0_off();
}

void tone(unsigned int frq,unsigned char duration){
	char i;
	if (frq!=0xffff){
		_tmr0_on(frq);
	    tmr_reload=frq;
	}
	for (i=0;i<duration;i++){
		pause(33);
	}
	_tmr0_off();
}

