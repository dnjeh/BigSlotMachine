#include "fixing.h"
//gcc -fdiagnostics-color=always -g .\main.c .\fixing.c .\src\buffer.c .\src\path.c .\src\draw.c .\src\read.c -o bsm.exe -lm
int bsmRunNow=-1;
clock_t bsmCurTime=0, bsmOldTime=0;

int main() {
    char t, tt[100];
    int i, j, now=0, luckynum;
    system("mode con cols=100 lines=45");
    system("chcp 65001");
    system("cls");
    
    pahInit();
    bufInit();
    bsmInit();
    drwInit();
    drwFirst();

    bufChange();
    _beginthreadex(NULL, 0, readChar, 0, 0, NULL);
    for(bsmFrameNow=0;;bsmFrameNow++) {
        if(bsmFrameNow>=50) {
            if(bsmIsAct) {
                bsmRunNow++;
            }
            bsmFrameNow=0;
        }
        //bsmOldTime = clock();
        drwConfig();
        //sprintf(tt, "%s: %d, %d, %d", bsmcData[0], bsmiData[0][0], bsmiData[0][4], bsmiData[0][8]);
        //drwAlarm(tt);
        if(bsmRunNow==-1) {
            if(bsmFrameNow>25) drwHandle(0, 1);
            else drwHandle(0, 0);
        }
        else {
            switch(bsmRunNow) {
            case 0:
                do {
                    luckynum=rand()%bsmDataCnt;
                } while(bsmcData[luckynum][0]);
                if(bsmFrameNow>=45) drwHandle(0, 0);
                else if(bsmFrameNow>=40) drwHandle(1, 0);
                else if(bsmFrameNow>=35) drwHandle(2, 0);
                else if(bsmFrameNow>=30) drwHandle(3, 0);
                else if(bsmFrameNow>=25) drwHandle(4, 0);
                else if(bsmFrameNow>=20) drwHandle(5, 0);
                else if(bsmFrameNow>=15) drwHandle(4, 0);
                else if(bsmFrameNow>=10) drwHandle(3, 0);
                else if(bsmFrameNow>=5) drwHandle(2, 0);
                else if(bsmFrameNow>=0) drwHandle(1, 0);
                break;
            case 1:
                break;
            default:
                bsmIsAct=0;
                bsmRunNow=-1;
                readIsAct=1;
                break;
            }
        }
        //bsmCurTime = clock();
        Sleep(20-bsmCurTime+bsmOldTime);
        bufChange();
    }
    bufRel();
}