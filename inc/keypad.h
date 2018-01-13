/*
 * keys.h
 *
 *  Created on: 2018-01-09
 *      Author: Jacques
 */

#include <SI_EFM8BB1_Register_Enums.h>

#ifndef INC_KEYPAD_H_
#define INC_KEYPAD_H_

#define KEY_NONE (0)
#define KEY_UP (1)
#define KEY_DOWN (2)
#define KEY_LEFT (4)
#define KEY_RIGHT (8)
#define KEY_A (16)
#define KEY_B (32)

extern unsigned char keypad_read();
extern unsigned char wait_key();
extern unsigned char key_down(uint8_t key);

#endif /* INC_KEYPAD_H_ */
