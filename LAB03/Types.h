/*Library*/
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

/*Variable Types*/
typedef unsigned char  uint8;
typedef unsigned short uint16;
typedef unsigned long  uint32;

/*Defines*/
#define TIME_A			4
#define TIME_B			3
#define TIME_C			5
#define INACTIVE_BOMB	0 

/*Prototypes*/
void BombConfAndExe ( void );
void delay ( uint16 u16MilliSeconds ); 