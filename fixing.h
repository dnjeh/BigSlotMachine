#include <stdio.h>   //만국공통
#include <conio.h>   //콘솔 관련 명령어 포함
#include <io.h>      //기억상, 파일 입출력 관련
#include <time.h>    //시간 관련
#include <windows.h> //콘솔2
#include <string.h>  //문자열 관련된 편리한 것들!
#include <errno.h>   //파일 쓸때 같이 씀
#include <process.h> //스레드 관련 헤더파일?

#define SLOT_SIZ_Y 42
#define SLOT_HANDLE_X 0
#define SLOT_HANDLE_Y 0
#define SLOT_INIT_X 17
#define SLOT_INIT_Y 1

#define 

extern FILE *fp, *fp2;

extern char pahCon[20];
extern char pahCsv[20];
extern char pahLog[20];
extern char pahRes[20];

extern HANDLE buf[2];
extern int bufNow;

extern int drwIsLet[7][3][20];
extern char drwLet[7][3][20][9][15];

//경로 관련 함수
void pahInit();

//화면 관련 함수
void bufInit();
void bufRel();
void bufChange();

//표현 관련 함수
void drwInit();
void drwHandle();

//스레드 관련 함수
unsigned __stdcall readChar(void *arg);