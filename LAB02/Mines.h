/*Variables*/

typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;

/*Definiciones*/

#define EASY_MODE				10
#define MEDIUM_MODE				20
#define HARD_MODE				30
#define HASHTAG_ASCII_VALUE		35
#define AT_ASCII_VALUE			64
#define MINES_MAP_SIZE			15
#define BASE_VALUE				11
#define BOMB_VALUE				12
#define EXPLODE					255
#define TOTAL_SPOTS				225

/*Prototipos*/
void ShowAllMapMines(uint8 au8Mines[15][15]);
void ShowMapMines(uint8 au8Mines[15][15]);
void MinesDifficulty(uint8 au8Mines[15][15], uint8 u8DifficultySelected);
uint8 CheckinMines(uint8 au8Mines[15][15], uint8 u8MinesRow, uint8 u8MinesColumn);