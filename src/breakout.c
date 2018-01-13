/*
 * breakout.c
 *
 *  Created on: 2018-01-12
 *      Author: Jacques
 */

#include "chip8.h"
#include "keypad.h"

#define min(a,b) (a)<(b)?(a):(b)
#define max(a,b) (a)>(b)?(a):(b)


// brick row gain
// rows are numbered from bottom to top.
#define ROW_1  (1)
#define ROW_2  (1)
#define ROW_3  (3)
#define ROW_4  (3)
#define ROW_5  (5)
#define ROW_6  (5)
#define ROW_7  (7)
#define ROW_8  (7)
#define ROW_8_Y (8)
#define BRIX_PER_ROW (15)
// bricks wall bounds
#define BRIX_LEFT_X (2)
#define BRIX_RIGHT_X (61)
#define BRIX_TOP_Y (8)
#define BRIX_BOTTOM_Y (15)
// play area bounds
#define TOP_BOUND (6)
#define LEFT_BOUND (0)
#define RIGHT_BOUND (63)
#define BOTTOM_BOUND (31)
#define BRIX_ROW_WIDTH (60)
// each brick is 4 pixels
#define BRIX_WIDTH (4)
// 8 rows of 15 bricks
#define BRIX_COUNT (8*15)
// there is a large and small paddle
// this is the width in pixels.
#define LARGE_PADDLE (8)
#define SMALL_PADDLE (4)
// 3 rounds per game.
#define GAME_ROUNDS (3)
// paddle movement bounds
#define PADDLE_LEFT_BOUND (1)
#define PADDLE_RIGHT_BOUND (63)
// ball speed delay
// small number is fast ball.
#define SPEED_SLOW (40)
#define SPEED_MEDIUM (20)
#define SPEED_FAST (10)
// numbers display position
#define DISPLAY_Y (0)
#define SCORE_X (0)
#define ROUND_X (12)
#define HSCORE_X (44)
// score gain for each row.
// 2 top rows earn the highest gain of 7.
char code gain[8]={ROW_8,ROW_7,ROW_6,ROW_5,ROW_4,ROW_3,ROW_2,ROW_1};

char paddle_pos; // paddle position
unsigned int score; // current score
unsigned int high_score; // highest score
char rounds; // number of rounds left in game.
char speed; // ball speed.
char paddle_used; // large or small paddle
char ball_x;
char ball_y;
char ball_dx; // {-1,1}
char x_factor;  // ball x speed factor {1,2}
char ball_dy; // {-1,1}
char new_round; // boolean
char paddle_dx; // {-1,1}
char paddle_last;// last paddle direction
char brix_left; // count of bricks left in game.

void draw_brix(){
	char x,y;

	for (y=BRIX_TOP_Y;y<=BRIX_BOTTOM_Y;y++)
		for (x=BRIX_LEFT_X;x<=BRIX_RIGHT_X;x++)
			xor_pixel(x,y);
}

void draw_walls(){
	char p;

	for (p=LEFT_BOUND;p<=RIGHT_BOUND;p++) xor_pixel(p,TOP_BOUND);
	for (p=TOP_BOUND+1;p<=BOTTOM_BOUND;p++){
		xor_pixel(LEFT_BOUND,p);
		xor_pixel(RIGHT_BOUND,p);
	}
}

void draw_paddle(){
	char x;

	for (x=paddle_pos;x<(paddle_pos+paddle_used);x++)
		xor_pixel(x,31);
}

void init_game(){
	paddle_used=LARGE_PADDLE;
	score=0;
	rounds=GAME_ROUNDS;
    speed=SPEED_SLOW;
    paddle_pos=(HRES-LARGE_PADDLE)/2;
	clr_scr();
	draw_walls();
	draw_brix();
	print_int(SCORE_X,DISPLAY_Y,score);
	print_int(ROUND_X,DISPLAY_Y,rounds);
	print_int(HSCORE_X,DISPLAY_Y,high_score);
	draw_paddle();
	paddle_dx=0;
	paddle_last=0;
	new_round=1;
	brix_left=BRIX_COUNT;
}

void wait_service(){
	char k;

    while(keypad_read());
	ball_y=30;
	ball_x=paddle_pos+(paddle_used>>1);
	xor_pixel(ball_x,ball_y);
	k=wait_key();
	ball_dy=-1;
	if (rand_bit()) ball_dx=1; else ball_dx=-1;
	if (rand_bit())x_factor=1;else x_factor=2;
	new_round=0;
}

char code bravo_msg[15]={
	0xce,0xea,0xe8,
	0xaa,0xaa,0xa8,
	0xcc,0xea,0xa8,
	0xaa,0xaa,0xa0,
	0xca,0xa4,0xe8
};

// got maximum score
void bravo(){
	char x,y,ofs,b;
	clr_scr();
	for (x=0;x<21;x++){
		ofs=x/8;
		b=x%8;
		for (y=0;y<5;y++){
			if (bravo_msg[ofs+y*3]&(1<<(7-b))){
				xor_pixel(63,13+y);
			}
		}
		scroll_left();
		pause(100);
	}
	for (x=0;x<22;x++){
		scroll_left();
		pause(100);
	}
}

char code breakout_msg[20]={
		0xce,0xee,0xae,0xae,
		0xaa,0x8a,0xaa,0xa4,
		0xcc,0xee,0xca,0xa4,
		0xaa,0x8a,0xaa,0xa4,
		0xca,0xea,0xae,0xe4
};

void breakout_screen(){
	unsigned char x,y,ofs,b;
	clr_scr();
	for (y=0;y<5;y++){
		ofs=4*y;
		for (x=0;x<32;x++){
			b=x%8;
			if (breakout_msg[ofs+x/8]&(1<<(7-b))){
				xor_pixel(16+x,13+y);
			}
		}
	}
	pause(1500);
	for (b=0;b<255;b++){
		pause(10);
		xor_pixel(16+random(5),12+random(3));
	}

}

void delete_brix(char x, char y){
	char i;
	x-=2;
	x&=0xfc;
	x+=2;
	for (i=0;i<BRIX_WIDTH;(i++,x++)) xor_pixel(x,y);
	brix_left--;
	if (! brix_left){
		bravo();
		rounds=0;
		return;
	}
	print_int(SCORE_X,DISPLAY_Y,score);
	score+=gain[y-ROW_8_Y];
	print_int(SCORE_X,DISPLAY_Y,score);
	if (ball_dy<0) ball_dy=-ball_dy;
	if ((y<9)&&(speed>SPEED_MEDIUM)) speed=SPEED_MEDIUM;
}

// return TRUE if collision with bricks wall.
char is_brix_collision(char x, char y){
	if ((x>=BRIX_LEFT_X) && (x<=BRIX_RIGHT_X)&&
		(y>=BRIX_TOP_Y)&& (y<=BRIX_BOTTOM_Y))
		return 1;
	else
		return 0;
}

// return TRUE if collision with area wall
char is_bound_collision(char x, char y){
	return (y==TOP_BOUND) || (x==LEFT_BOUND) || (x==RIGHT_BOUND);
}

// return TRUE if collision with paddle
char is_paddle_collision(char x, char y){
	return ((y==BOTTOM_BOUND) && (x>=paddle_pos) && (x<(paddle_pos+paddle_used)));
}

void check_collision(){
	noise(10);
	xor_pixel(ball_x,ball_y);
	if (is_brix_collision(ball_x,ball_y)){
		delete_brix(ball_x,ball_y);
	}else if (is_bound_collision(ball_x,ball_y)){
		if (ball_y==TOP_BOUND) ball_dy=-ball_dy;
		if ((ball_x==LEFT_BOUND)||(ball_x==RIGHT_BOUND)){
			ball_dx=-ball_dx;
			if (ball_dy==BOTTOM_BOUND){
				ball_dy-=ball_dy;
			}
		}
	}else{// paddle collision
		ball_dy=-ball_dy;
		if ((ball_x==paddle_pos)||(ball_x==(paddle_pos+paddle_used-1))){
			x_factor=2;
		}
	}
	xor_pixel(ball_x,ball_y);
}

void move_ball(){
	xor_pixel(ball_x,ball_y);
	ball_x+=ball_dx*x_factor;
	if (ball_x<LEFT_BOUND){
		ball_x=LEFT_BOUND;
	}else if (ball_x>RIGHT_BOUND){
		ball_x=RIGHT_BOUND;
	}
	ball_y+=ball_dy;
	if (ball_y>BOTTOM_BOUND){
		ball_y=BOTTOM_BOUND;
	}else if (ball_y<TOP_BOUND){
		ball_y=TOP_BOUND;
	}
	if (xor_pixel(ball_x,ball_y)){
		check_collision();
	}else if (ball_y==31){
		xor_pixel(ball_x,ball_y);
		print_int(ROUND_X,DISPLAY_Y,rounds);
		rounds--;
		print_int(ROUND_X,DISPLAY_Y,rounds);
		new_round=1;
	}
}

#define LEFT (0)
#define RIGHT (1)
void move_paddle(char direction){
	draw_paddle();
	if (direction==paddle_last){
		if (paddle_dx<4)paddle_dx++;
	}else{
		paddle_dx=1;
	}
	if (direction){
		if (paddle_pos<(PADDLE_RIGHT_BOUND-paddle_used)){
			paddle_pos=min(paddle_pos+paddle_dx,PADDLE_RIGHT_BOUND-paddle_used);
		}
	}else{
		if (paddle_pos>PADDLE_LEFT_BOUND){
			paddle_pos=max(paddle_pos-paddle_dx,PADDLE_LEFT_BOUND);
		}
	}
	draw_paddle();
	paddle_last=direction;
}

// game over animation
void game_over(){
	char i;
	unsigned int frq;
	frq=65380;
	for (i=0;i<32;i++){
	   scroll_down(1);
	   tone(frq,2);
	   frq-=70;
	}
}

void breakout(){
	char k;
	  init_game();
	  while (rounds){
		  if (new_round) wait_service();
		  move_ball();
		  k=keypad_read();
		  switch (k){
		  case KEY_LEFT:
			  move_paddle(LEFT);
			  break;
		  case KEY_RIGHT:
			  move_paddle(RIGHT);
			  break;
		  default:
			  paddle_dx=1;
		  }
		  pause(speed);
	  }
	  game_over();
	  if (score>high_score) high_score=score;
}


