#include <stdio.h>   //만국공통
#include <stdlib.h>  //랜덤 전용
#include <conio.h>   //콘솔 관련 명령어 포함
#include <io.h>      //기억상, 파일 입출력 관련
#include <time.h>    //시간 관련
#include <windows.h> //콘솔2
#include <string.h>  //문자열 관련된 편리한 것들!
#include <errno.h>   //파일 쓸때 같이 씀
#include <process.h> //스레드 관련 헤더파일?

#define SLOT_SIZ_Y 42
#define SLOT_HANDLE_X 7
#define SLOT_HANDLE_Y 10
#define SLOT_HANDLE_BALL_X 5
#define SLOT_HANDLE_BALL_Y 10
#define SLOT_HANDLE_SIZ_X 10
#define SLOT_HANDLE_SIZ_Y 10
#define SLOT_HANDLE_BALL_SIZ_X 9
#define SLOT_HANDLE_BALL_SIZ_Y 5
#define SLOT_INIT_X 17
#define SLOT_INIT_Y 1

#define SLOT_SLOT0_X 23
#define SLOT_SLOT1_X 43
#define SLOT_SLOT2_X 63
#define SLOT_SLOT_Y 14

#define LET_MAX_Y 9
#define LET_MAX_X 15
#define LET_JA_MAX 19
#define LET_JAJA_MAX 30
#define LET_14_MO_MAX 9
#define LET_25_MO_MAX 5
#define LET_36_MO_MAX 7

#define CON_LINE_X 34
#define CON_LINE0_Y 33
#define CON_LINE1_Y 34
#define CON_LINE2_Y 36
#define CON_LINE3_Y 37

#define DRW_ALARM_X 31
#define DRW_ALARM_Y 26

extern FILE *fp, *fp2;

extern char pahCon[20];
extern char pahCsv[20];
extern char pahLog[20];
extern char pahRes[20];

extern HANDLE buf[2];
extern int bufNow;

extern int drwIsLet[7][4][31];
extern char drwLet[7][4][31][9][20];
extern char drwCHandle[SLOT_HANDLE_SIZ_Y][SLOT_HANDLE_SIZ_X+5];
extern char drwCHandleBall[2][SLOT_HANDLE_BALL_SIZ_Y][SLOT_HANDLE_BALL_SIZ_X+6];

extern int readIsAct;

extern int bsmIsAct;
extern int bsmIsRealRand;
extern int bsmIsRmName;

extern clock_t bsmCurTime, bsmOldTime;
extern int bsmFrameNow;
extern int bsmRunNow;

extern int bsmiData[100][9];
extern int bsmDataCnt;
extern char bsmcData[100][50];

//
void bsmInit();
void rmEnt(char *str, int siz);

//경로 관련 함수
void pahInit();

//화면 관련 함수
void bufInit();
void bufRel();
void bufChange();

//표현 관련 함수
void drwInit();
void drwBuf(int y, int x, char *str);
void drwFullBuf(int y, int x, char *str);
void drwFirst();
void drwHandle(int dy, int f);
void drwConfig();
void drwAlarm(char *str);
void drwSlot(int sind, int dy, int t, int tt, int ttt);
void drwAreaSlot(int y, int x, int t, int tt, int ttt);

//스레드(입력) 관련 함수
unsigned __stdcall readChar(void *arg);