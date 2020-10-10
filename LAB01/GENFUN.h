
/*Tipos de Datos*/
typedef unsigned char 	uint8;
typedef unsigned short 	uint16;
typedef unsigned long 	uint32;

/*Definiciones*/
#define ASCII_HIGH_TRESHOLD_OFF_ON	123	//ASCII value of '`'
#define ASCII_LOW_TRESHOLD_OFF_ON	96	//ASCII value of '{'
#define ASCII_HIGH_TRESHOLD_ON_OFF	91	//ASCII value of '['
#define ASCII_LOW_TRESHOLD_ON_OFF	64	//ASCII value of '@'
#define ASCII_CONVERTION_FACTOR		32	//Name to add or substract to change Caps 
#define ASCII_CHARACTER_TARGETED 	97	//ASCII value of 'a'
#define ASCII_CHARACTER_OVERWRITE	178	//ASCII value of '▓'
#define NUMBERS_BEING_AVERAGED		3	//Total of numbers to get an average
#define LIST_TOTAL					10	//Total of the numbers used for the list
#define VARIABLE_CHAR_HIGH_TRESHOLD	256 //Hightest value of char (8 BYTES) 
#define HIGH_TRESHOLD_SIGNALS      	200	// Maximum of the graph
#define LOW_TRESHOLD_SIGNALS       	100	// Minimum of the graph

/*Prototipos de Funciones*/
void GENFUN_vCapsOn ( uint8 *pu8Src, uint8 u8SizeOfList );
void GENFUN_vCapsOff ( uint8 *pu8Src, uint8 u8SizeOfList );
uint8 GENFUN_u8GetOccurence ( uint8 *pu8Src, uint8 u8Target, uint8 u8SizeOfList );
uint8 GENFUN_u8GetAverage ( uint8 *pu8Src, uint8 u8SizeOfList );
void GENFUN_u8MemSet ( uint8 *pu8Src, uint8 u8Char2Set, uint8 u8SizeOfList );
void GENFUN_u8MemCopy ( uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList );
void GENFUN_vSortList ( uint8 *pu8Src, uint8 *pu8Dest, uint8 u8SizeOfList );
void GENFUN_vSoftSignal ( uint8 *pu8Src, uint8 *pu8Dest );
void GENFUN_vFilterSignal ( uint8 *pu8Src, uint8 *pu8Dest, uint8 u8MaxVal, uint8 u8MinVal );