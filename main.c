        #pragma config PLLDIV   = 5         // (20 MHz crystal on PICDEM FS USB board)
        #pragma config CPUDIV   = OSC1_PLL2  
        #pragma config USBDIV   = 2         // Clock source from 96MHz PLL/2
        #pragma config FOSC     = HSPLL_HS
        #pragma config FCMEN    = OFF
        #pragma config IESO     = OFF
        #pragma config PWRT     = OFF
        #pragma config BOR      = ON
        #pragma config BORV     = 3
        #pragma config VREGEN   = ON      //USB Voltage Regulator
        #pragma config WDT      = OFF
        #pragma config WDTPS    = 32768
        #pragma config MCLRE    = ON
        #pragma config LPT1OSC  = OFF
        #pragma config PBADEN   = OFF
//      #pragma config CCP2MX   = ON
        #pragma config STVREN   = ON
        #pragma config LVP      = OFF
//      #pragma config ICPRT    = OFF       // Dedicated In-Circuit Debug/Programming
        #pragma config XINST    = OFF       // Extended Instruction Set
        #pragma config CP0      = OFF
        #pragma config CP1      = OFF
//      #pragma config CP2      = OFF
//      #pragma config CP3      = OFF
        #pragma config CPB      = OFF
//      #pragma config CPD      = OFF
        #pragma config WRT0     = OFF
        #pragma config WRT1     = OFF
//      #pragma config WRT2     = OFF
//      #pragma config WRT3     = OFF
        #pragma config WRTB     = OFF       // Boot Block Write Protection
        #pragma config WRTC     = OFF
//      #pragma config WRTD     = OFF
        #pragma config EBTR0    = OFF
        #pragma config EBTR1    = OFF
//      #pragma config EBTR2    = OFF
//      #pragma config EBTR3    = OFF
        #pragma config EBTRB    = OFF

#include <p18f4553.h>
#include "hd44780.h"
#include "delay.h"

#define mInitAllLEDs()     {TRISBbits.TRISB6=0; TRISBbits.TRISB7=0;}
#define mLED_1              LATBbits.LATB6
#define mLED_2              LATBbits.LATB7

rom char battery1[8] = {
        0b01110,
    	0b01010,
    	0b10001,
    	0b10001,
    	0b10001,
    	0b10001,
    	0b10001,
    	0b11111
    };

rom char battery2[8] = {
        0b01110,
    	0b01010,
    	0b10001,
    	0b10001,
    	0b10001,
    	0b10001,
    	0b11111,
    	0b11111
    };
	
rom char battery3[8] = {
        0b01110,
    	0b01010,
    	0b10001,
    	0b10001,
    	0b10001,
    	0b11111,
    	0b11111,
    	0b11111
    };

rom char battery4[8] = {
        0b01110,
    	0b01010,
    	0b10001,
    	0b10001,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111
    };

rom char battery5[8] = {
        0b01110,
    	0b01010,
    	0b10001,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111
    };

rom char battery6[8] = {
        0b01110,
    	0b01010,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111
    };

rom char battery7[8] = {
        0b01110,
    	0b01110,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111,
    	0b11111
    };

void main()
{
	mInitAllLEDs();
	delay1Second();
	mLED_1 = 1;
	mLED_2 = 1;
	HD44780_Init();
	mLED_1 = 0;
	mLED_2 = 0;
	HD44780_AddCharacter(0, battery1);
	HD44780_AddCharacter(1, battery2);
	HD44780_AddCharacter(2, battery3);
	HD44780_AddCharacter(3, battery4);
	HD44780_AddCharacter(4, battery5);
	HD44780_AddCharacter(5, battery6);
	HD44780_AddCharacter(6, battery7);
	HD44780_GoToPoint(1,1);
	HD44780_WriteString("Battery State");
	HD44780_GoToPoint(2,1);
	HD44780_WriteData(0x00);
	HD44780_WriteData(0x01);
	HD44780_WriteData(0x02);
	HD44780_WriteData(0x03);
	HD44780_WriteData(0x04);
	HD44780_WriteData(0x05);
	HD44780_WriteData(0x06);

	while(1)
	{
		delay1Second();
		mLED_1 = 1;
		mLED_2 = 0;
		delay1Second();
		mLED_1 = 0;
		mLED_2 = 1;
	}
}

	