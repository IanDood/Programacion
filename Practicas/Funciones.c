#include "stdio.h"

typedef unsigned char uint8;
typedef unsigned short uint16;

uint16 vCalcSum( uint8 u8FirstNumber, uint8 u8SecondNumber );
uint16 vCalcMult( uint8 u8FirstNumber, uint8 u8SecondNumber );
uint16 vCalcDiv( uint8 u8FirstNumber, uint8 u8SecondNumber );
uint8 vCalcSub( uint8 u8FirstNumber, uint8 u8SecondNumber );

void main( void )
{
	uint16 u16Result;
	u16Result = vCalcSum(5, 10);
	printf("Este es el resultado: %d\n", u16Result );
	u16Result = vCalcMult(5, 8);
	printf("Este es el resultado: %d\n", u16Result );
	u16Result = vCalcDiv(10, 5);
	printf("Este es el resultado: %d\n", u16Result );
	u16Result = vCalcSub(5, 3);
	printf("Este es el resultado: %d\n", u16Result );
}

uint16 vCalcSum( uint8 u8FirstNumber, uint8 u8SecondNumber )
{
	return (u8FirstNumber + u8SecondNumber);
}

uint16 vCalcMult( uint8 u8FirstNumber, uint8 u8SecondNumber )
{
	return (u8FirstNumber * u8SecondNumber);
}

uint16 vCalcDiv( uint8 u8FirstNumber, uint8 u8SecondNumber )
{
	uint16 u16Result = 0;

	if ( u8SecondNumber == 0)
	{
		printf("No funcionara con 0.\n");
	}
	else
	{
		u16Result = (u8FirstNumber / u8SecondNumber);
	}

	return u16Result;
}

uint8 vCalcSub( uint8 u8FirstNumber, uint8 u8SecondNumber )
{
	uint8 u8Result = 0;

	if ( u8SecondNumber > u8FirstNumber )
	{
		printf("Revisa tus numeros.\n");
	}
	else
	{
		u8Result = (u8FirstNumber - u8SecondNumber);
	}

	return u8Result;
}