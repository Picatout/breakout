EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:librairie-personnelle
LIBS:BBchip8-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L EFM8BB10F8G_SOIC16 U1
U 1 1 5A3BD9BC
P 5500 3850
F 0 "U1" H 5350 3900 60  0000 C CNN
F 1 "EFM8BB10F8G_SOIC16" H 5350 4700 60  0000 C CNN
F 2 "" H 5500 3850 60  0001 C CNN
F 3 "" H 5500 3850 60  0001 C CNN
	1    5500 3850
	1    0    0    -1  
$EndComp
$Comp
L R R1
U 1 1 5A3BDCAD
P 4600 2700
F 0 "R1" V 4680 2700 50  0000 C CNN
F 1 "82" V 4600 2700 50  0000 C CNN
F 2 "" V 4530 2700 50  0000 C CNN
F 3 "" H 4600 2700 50  0000 C CNN
	1    4600 2700
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 5A3BDCF0
P 6450 2700
F 0 "R2" V 6530 2700 50  0000 C CNN
F 1 "680" V 6450 2700 50  0000 C CNN
F 2 "" V 6380 2700 50  0000 C CNN
F 3 "" H 6450 2700 50  0000 C CNN
	1    6450 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3350 6450 3350
Wire Wire Line
	6450 3350 6450 2850
Wire Wire Line
	4650 3150 4600 3150
Wire Wire Line
	4600 3150 4600 2850
Wire Wire Line
	4600 2550 6600 2550
$Comp
L RCA_JACK J1
U 1 1 5A3BDD5C
P 7100 2550
F 0 "J1" H 7100 2650 60  0000 C CNN
F 1 "video out" V 7100 3000 60  0000 C CNN
F 2 "" H 7100 2550 60  0000 C CNN
F 3 "" H 7100 2550 60  0000 C CNN
	1    7100 2550
	0    1    1    0   
$EndComp
Connection ~ 6450 2550
$Comp
L GND #PWR7
U 1 1 5A3BDDD1
P 7100 2900
F 0 "#PWR7" H 7100 2650 50  0001 C CNN
F 1 "GND" H 7100 2750 50  0000 C CNN
F 2 "" H 7100 2900 50  0000 C CNN
F 3 "" H 7100 2900 50  0000 C CNN
	1    7100 2900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 5A3BDDED
P 4300 3750
F 0 "#PWR4" H 4300 3500 50  0001 C CNN
F 1 "GND" H 4300 3600 50  0000 C CNN
F 2 "" H 4300 3750 50  0000 C CNN
F 3 "" H 4300 3750 50  0000 C CNN
	1    4300 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 3750 4650 3750
$Comp
L C C2
U 1 1 5A3BDE15
P 3800 4100
F 0 "C2" H 3825 4200 50  0000 L CNN
F 1 "100nF" H 3825 4000 50  0000 L CNN
F 2 "" H 3838 3950 50  0000 C CNN
F 3 "" H 3800 4100 50  0000 C CNN
	1    3800 4100
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 5A3BDE6D
P 3400 4100
F 0 "C1" H 3425 4200 50  0000 L CNN
F 1 "1µF" H 3425 4000 50  0000 L CNN
F 2 "" H 3438 3950 50  0000 C CNN
F 3 "" H 3400 4100 50  0000 C CNN
	1    3400 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 3950 4650 3950
Connection ~ 3800 3950
$Comp
L GND #PWR2
U 1 1 5A3BDEBB
P 3400 4250
F 0 "#PWR2" H 3400 4000 50  0001 C CNN
F 1 "GND" H 3400 4100 50  0000 C CNN
F 2 "" H 3400 4250 50  0000 C CNN
F 3 "" H 3400 4250 50  0000 C CNN
	1    3400 4250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR3
U 1 1 5A3BDEF4
P 3800 4250
F 0 "#PWR3" H 3800 4000 50  0001 C CNN
F 1 "GND" H 3800 4100 50  0000 C CNN
F 2 "" H 3800 4250 50  0000 C CNN
F 3 "" H 3800 4250 50  0000 C CNN
	1    3800 4250
	1    0    0    -1  
$EndComp
$Comp
L Battery BT1
U 1 1 5A3BDF2F
P 2300 4150
F 0 "BT1" H 2400 4200 50  0000 L CNN
F 1 "CR2450" H 2400 4100 50  0000 L CNN
F 2 "" V 2300 4190 50  0000 C CNN
F 3 "" V 2300 4190 50  0000 C CNN
	1    2300 4150
	1    0    0    -1  
$EndComp
$Comp
L SPST SW1
U 1 1 5A3BDF70
P 2900 3950
F 0 "SW1" H 2900 4050 50  0000 C CNN
F 1 "power" H 2900 3850 50  0000 C CNN
F 2 "" H 2900 3950 50  0000 C CNN
F 3 "" H 2900 3950 50  0000 C CNN
	1    2900 3950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 3950 2300 3950
Wire Wire Line
	2300 3950 2300 4000
$Comp
L GND #PWR1
U 1 1 5A3BDFFE
P 2300 4300
F 0 "#PWR1" H 2300 4050 50  0001 C CNN
F 1 "GND" H 2300 4150 50  0000 C CNN
F 2 "" H 2300 4300 50  0000 C CNN
F 3 "" H 2300 4300 50  0000 C CNN
	1    2300 4300
	1    0    0    -1  
$EndComp
$Comp
L RCA_JACK J2
U 1 1 5A3BE02E
P 8300 4100
F 0 "J2" H 8300 4200 60  0000 C CNN
F 1 "audio out" V 8300 4550 60  0000 C CNN
F 2 "" H 8300 4100 60  0000 C CNN
F 3 "" H 8300 4100 60  0000 C CNN
	1    8300 4100
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 5A3BE0D3
P 6550 3950
F 0 "R3" V 6630 3950 50  0000 C CNN
F 1 "2k2" V 6550 3950 50  0000 C CNN
F 2 "" V 6480 3950 50  0000 C CNN
F 3 "" H 6550 3950 50  0000 C CNN
	1    6550 3950
	0    1    1    0   
$EndComp
$Comp
L C C3
U 1 1 5A3BE126
P 7500 4250
F 0 "C3" H 7525 4350 50  0000 L CNN
F 1 "47nF" H 7525 4150 50  0000 L CNN
F 2 "" H 7538 4100 50  0000 C CNN
F 3 "" H 7500 4250 50  0000 C CNN
	1    7500 4250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR9
U 1 1 5A3BE17A
P 7500 4400
F 0 "#PWR9" H 7500 4150 50  0001 C CNN
F 1 "GND" H 7500 4250 50  0000 C CNN
F 2 "" H 7500 4400 50  0000 C CNN
F 3 "" H 7500 4400 50  0000 C CNN
	1    7500 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR12
U 1 1 5A3BE1A6
P 8300 4450
F 0 "#PWR12" H 8300 4200 50  0001 C CNN
F 1 "GND" H 8300 4300 50  0000 C CNN
F 2 "" H 8300 4450 50  0000 C CNN
F 3 "" H 8300 4450 50  0000 C CNN
	1    8300 4450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6200 3950 6400 3950
$Comp
L R R4
U 1 1 5A3BE265
P 7800 4250
F 0 "R4" V 7880 4250 50  0000 C CNN
F 1 "1K" V 7800 4250 50  0000 C CNN
F 2 "" V 7730 4250 50  0000 C CNN
F 3 "" H 7800 4250 50  0000 C CNN
	1    7800 4250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR11
U 1 1 5A3BE2CE
P 7800 4400
F 0 "#PWR11" H 7800 4150 50  0001 C CNN
F 1 "GND" H 7800 4250 50  0000 C CNN
F 2 "" H 7800 4400 50  0000 C CNN
F 3 "" H 7800 4400 50  0000 C CNN
	1    7800 4400
	1    0    0    -1  
$EndComp
Text GLabel 3400 3950 1    39   Input ~ 0
+3V
Wire Wire Line
	7800 3950 7800 4100
$Comp
L SW_PUSH_SMALL SW5
U 1 1 5A3BEB5A
P 5750 5500
F 0 "SW5" V 5750 5700 50  0000 C CNN
F 1 "BTN_RT" V 5700 5350 50  0000 C CNN
F 2 "" H 5750 5500 50  0000 C CNN
F 3 "" H 5750 5500 50  0000 C CNN
	1    5750 5500
	0    -1   -1   0   
$EndComp
$Comp
L SW_PUSH_SMALL SW3
U 1 1 5A3BF0F2
P 5350 5150
F 0 "SW3" H 5500 5260 50  0000 C CNN
F 1 "BTN_UP" H 5600 5150 50  0000 C CNN
F 2 "" H 5350 5150 50  0000 C CNN
F 3 "" H 5350 5150 50  0000 C CNN
	1    5350 5150
	-1   0    0    -1  
$EndComp
$Comp
L SW_PUSH_SMALL SW2
U 1 1 5A3BF16A
P 4850 5500
F 0 "SW2" H 5000 5610 50  0000 C CNN
F 1 "BTN_LT" H 5100 5450 50  0000 C CNN
F 2 "" H 4850 5500 50  0000 C CNN
F 3 "" H 4850 5500 50  0000 C CNN
	1    4850 5500
	-1   0    0    -1  
$EndComp
$Comp
L SW_PUSH_SMALL SW4
U 1 1 5A3BF1E1
P 5350 5900
F 0 "SW4" H 5550 5900 50  0000 C CNN
F 1 "BTN_DN" H 5200 5850 50  0000 C CNN
F 2 "" H 5350 5900 50  0000 C CNN
F 3 "" H 5350 5900 50  0000 C CNN
	1    5350 5900
	-1   0    0    -1  
$EndComp
NoConn ~ 4650 3350
NoConn ~ 4650 3550
NoConn ~ 4650 4150
NoConn ~ 4650 4350
Wire Wire Line
	5250 5250 5250 6000
Connection ~ 5250 5600
$Comp
L GND #PWR5
U 1 1 5A3BFCA6
P 4750 5750
F 0 "#PWR5" H 4750 5500 50  0001 C CNN
F 1 "GND" H 4750 5600 50  0000 C CNN
F 2 "" H 4750 5750 50  0000 C CNN
F 3 "" H 4750 5750 50  0000 C CNN
	1    4750 5750
	1    0    0    -1  
$EndComp
Wire Wire Line
	4750 5600 4750 5750
Text Label 5450 5050 0    39   ~ 0
UP
Text Label 5850 5400 0    39   ~ 0
RIGHT
Text Label 4950 5400 0    39   ~ 0
LEFT
Text Label 5450 5800 0    39   ~ 0
DOWN
Text Label 6200 4150 0    39   ~ 0
UP
Text Label 6200 4350 0    39   ~ 0
DOWN
Text Label 6200 4550 0    39   ~ 0
LEFT
Text Label 4650 4550 2    39   ~ 0
RIGHT
$Comp
L SW_PUSH_SMALL SW6
U 1 1 5A3C59EE
P 6500 5350
F 0 "SW6" H 6650 5460 50  0000 C CNN
F 1 "BTN_A" H 6700 5350 50  0000 C CNN
F 2 "" H 6500 5350 50  0000 C CNN
F 3 "" H 6500 5350 50  0000 C CNN
	1    6500 5350
	1    0    0    -1  
$EndComp
$Comp
L SW_PUSH_SMALL SW7
U 1 1 5A3C5A41
P 7350 5350
F 0 "SW7" H 7500 5460 50  0000 C CNN
F 1 "BTN_B" H 7550 5350 50  0000 C CNN
F 2 "" H 7350 5350 50  0000 C CNN
F 3 "" H 7350 5350 50  0000 C CNN
	1    7350 5350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR6
U 1 1 5A3C5A99
P 6600 5450
F 0 "#PWR6" H 6600 5200 50  0001 C CNN
F 1 "GND" H 6600 5300 50  0000 C CNN
F 2 "" H 6600 5450 50  0000 C CNN
F 3 "" H 6600 5450 50  0000 C CNN
	1    6600 5450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR8
U 1 1 5A3C5ADA
P 7450 5450
F 0 "#PWR8" H 7450 5200 50  0001 C CNN
F 1 "GND" H 7450 5300 50  0000 C CNN
F 2 "" H 7450 5450 50  0000 C CNN
F 3 "" H 7450 5450 50  0000 C CNN
	1    7450 5450
	1    0    0    -1  
$EndComp
Text Label 7250 5250 2    60   ~ 0
B
Text Label 6400 5250 2    60   ~ 0
A
Text Label 6200 3550 0    60   ~ 0
A
Text Label 6200 3750 0    60   ~ 0
B
$Comp
L MXO45HS U2
U 1 1 5A3C648B
P 8050 3650
F 0 "U2" H 7950 3750 60  0000 C CNN
F 1 "MXO45HS" H 7950 4250 39  0000 C CNN
F 2 "" H 8050 3650 60  0000 C CNN
F 3 "" H 8050 3650 60  0000 C CNN
	1    8050 3650
	1    0    0    -1  
$EndComp
Text Label 8350 3450 0    60   ~ 0
clock
Text Label 6200 3150 0    60   ~ 0
clock
$Comp
L GND #PWR10
U 1 1 5A3C6631
P 7600 3450
F 0 "#PWR10" H 7600 3200 50  0001 C CNN
F 1 "GND" H 7600 3300 50  0000 C CNN
F 2 "" H 7600 3450 50  0000 C CNN
F 3 "" H 7600 3450 50  0000 C CNN
	1    7600 3450
	1    0    0    -1  
$EndComp
Text GLabel 8350 2850 1    39   Input ~ 0
+3V
Wire Wire Line
	8350 2850 8350 3150
Text Notes 8350 3550 0    60   ~ 0
25,175Mhz\n
Wire Wire Line
	4750 5600 5650 5600
Text Label 6200 3350 0    60   ~ 0
sync
Text Label 4600 3150 2    60   ~ 0
video
Wire Wire Line
	6700 3950 7800 3950
Wire Wire Line
	7500 3950 7500 4100
Connection ~ 7500 3950
$EndSCHEMATC
