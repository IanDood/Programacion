/*Tipos de Datos*/

typedef unsigned char uint8;
typedef unsigned short uint16;

/*Definiciones*/

#define ACCOUNT_NUMBER	15
#define CARD_SIZE		16
#define NUMBER_TRESHOLD	9

/*Prototipos de Funciones*/

uint8 u8LuhnCheck ( uint8 *pu8Data );
