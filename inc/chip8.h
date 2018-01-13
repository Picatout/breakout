/*
 * chip8.h
 *
 *  Created on: 2018-01-03
 *      Author: Jacques
 */

#ifndef INC_CHIP8_H_
#define INC_CHIP8_H_

// graphics resolution
#define HBYTES (8)
#define HRES (64)
#define VRES (32)

// sound effects
#define BEEP (1)
#define UP_SWEEP (2)
#define WARBLE (3)
#define DOWN_SWEEP (4)
#define TRIANGLE_SWEEP (5)

extern unsigned  char xdata video[256];
extern unsigned int tmr_reload;

// functions prototypes
extern char xor_pixel(char x, char y);
extern char draw_sprite(char x, char y, char width,char height, char* sprite);
extern void clr_scr();
extern void scroll_down(char lines);
extern void scroll_up(char lines);
extern void scroll_left();
extern void scroll_right();
extern void pause(unsigned int msec);
extern void draw_digit(char x, char y, char digit);
extern void print_int(char x, char y, unsigned int u);
extern void sound_fx(unsigned char snd, unsigned char msec);
extern void noise(unsigned char msec);
extern void tone(unsigned int frq,unsigned char msec);
extern char rand_bit();
extern unsigned random(char n);

#endif /* INC_CHIP8_H_ */
