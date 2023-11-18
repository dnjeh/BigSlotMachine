#include <stdio.h>   //만국공통
#include <conio.h>   //콘솔 관련 명령어 포함
#include <io.h>      //기억상, 파일 입출력 관련
#include <time.h>    //시간 관련
#include <windows.h> //콘솔2
#include <string.h>  //문자열 관련된 편리한 것들!
#include <errno.h>   //파일 쓸때 같이 씀
#include <process.h> //스레드 관련 헤더파일?

static HANDLE bsmBuf[2];
static int bsmNowBuf;
static int usedGacha;
static int usedSlot;

//화면 관련 함수
void bufChange();

//스레드 관련 함수
unsigned __stdcall clickthr(void *arg);
unsigned __stdcall gachaScroll(void *arg);
unsigned __stdcall gachaUpdate(void *arg);
unsigned __stdcall slot(void *arg);

void ScreenInit() {
    CONSOLE_CURSOR_INFO cci;

    // 화면 버퍼 2개를 만든다.
    bsmBuf[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    bsmBuf[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);

    // 커서를 숨긴다.
    cci.dwSize = 1;
    cci.bVisible = 0;
    SetConsoleCursorInfo(bsmBuf[0], &cci);
    SetConsoleCursorInfo(bsmBuf[1], &cci);
}
