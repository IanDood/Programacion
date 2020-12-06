/*Library*/
#include "BombA.h"
#include "BombB.h"
#include "BombC.h"

/*BigMainLoop*/
void BombConfAndExe ( void ) 
{ 
	uint16 u16MilliSeconds = 0;
	static uint8 u8FlagBombA = TIME_A; 
	static uint8 u8FlagBombB = TIME_B; 
	static uint8 u8FlagBombC = TIME_C; 
	static uint8 u8ConfigurationMenu = 0; 
 
	while( u8ConfigurationMenu != 1 ) 
	{ 
		printf("\n\nSystem Configuration\n"); 
 
		printf("Selecting Time in Seconds (Bomb A): "); 
		scanf("%d", &u8FlagBombA); 
 
		printf("Selecting Time in Seconds (Bomb B): "); 
		scanf("%d", &u8FlagBombB); 
 
		printf("Selecting Time in Seconds (Bomb C): "); 
		scanf("%d", &u8FlagBombC); 
 
		printf("\nConfirmation of Bomb Configuration (Select Yes (1) or No (0))\n");
		printf("Selection: "); 
		scanf("%d", &u8ConfigurationMenu);
	} 
 
	if( u8FlagBombA == INACTIVE_BOMB ) 
	{ 
		/*Nothing To Do*/ 
	}   
	else  
	{ 
	   BombA( u8FlagBombA ); 
       u8FlagBombA--; 
	}

	if( u8FlagBombB == INACTIVE_BOMB ) 
	{ 
		/*Nothing To Do*/
	}   
	else  
	{ 
		BombB( u8FlagBombB ); 
		u8FlagBombB--; 
	}

	if( u8FlagBombC == INACTIVE_BOMB ) 
	{ 
		/*Nothing To Do*/ 
	}   
	else  
	{ 
		BombC( u8FlagBombC ); 
		u8FlagBombC--; 
	} 
 
	if(u8FlagBombA == 0 && u8FlagBombB == 0 && u8FlagBombC == 0) 
	{ 
		printf("\n\nProcess Has Ended, going back to System Configuration.\n");
		u8ConfigurationMenu = 0;
	}	
	else 
	{ 
		/*Nothing To Do*/
	}

	delay(1000); 
} 

/*Functions*/
void delay ( uint16 u16MilliSeconds ) 
{ 
	/*Converting time into milli_seconds*/ 
	int milli_seconds = u16MilliSeconds;

	/*Storing start time*/  
	clock_t start_time = clock();

	/*Looping till required time is not achieved*/
	while (clock() < start_time + milli_seconds ); 
}