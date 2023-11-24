#include "fixing.h"
//gcc -fdiagnostics-color=always -g .\main.c .\fixing.c .\src\buffer.c .\src\path.c .\src\draw.c .\src\read.c -o bsm.exe -lm
int main() {
    char t;
    int i, j;
    system("mode con cols=100 lines=45");
    system("chcp 65001");
    system("cls");
    
    pahInit();
    bufInit();
    drwInit();
    drwFirst();
    bsmInit();

    bufChange();
    _beginthreadex(NULL, 0, readChar, 0, 0, NULL);
    for(bsmFrameNow=0;;bsmFrameNow++) {
        if(bsmFrameNow>=50) bsmFrameNow=0;
        drwConfig();
        if(bsmFrameNow>25) drwHandle(0, 1);
        else drwHandle(0, 0);
        drwAlarm(bsmcData[0]);
        Sleep(20);
        bufChange();
    }
    bufRel();
}