#include "fixing.h"
//gcc -fdiagnostics-color=always -g .\main.c .\fixing.c .\src\buffer.c .\src\path.c .\src\draw.c .\src\read.c -o bsm.exe -lm
int bsmRunNow=-1;
clock_t bsmCurTime=0, bsmOldTime=0;

int main() {
    char t, tt[100];
    int i, j, now=0, luckynum=0, fpre, fnow, fFrame, cham;
    system("mode con cols=100 lines=45");
    system("chcp 65001");
    system("cls");
    
    pahInit();
    bufInit();
    bsmInit();
    drwInit();
    drwFirst();

    luckynum=bsmDataCnt-1;
    bufChange();
    _beginthreadex(NULL, 0, readChar, 0, 0, NULL);
    for(bsmFrameNow=0;;bsmFrameNow++) {
        if(bsmFrameNow>=50) {
            if(bsmIsAct&&bsmRunNow==-1) {
                bsmRunNow=0;
            }
            bsmFrameNow=0;
        }
        bsmOldTime = clock();
        drwConfig();
        //sprintf(tt, "%s: %d, %d, %d", bsmcData[0], bsmiData[0][0], bsmiData[0][4], bsmiData[0][8]);
        //drwAlarm(tt);
        if(bsmRunNow==-1) {
            if(bsmFrameNow>25) drwHandle(0, 1);
            else drwHandle(0, 0);
        }
        else {
            if(!bsmRunNow) {
                if(bsmFrameNow==0) {
                    fnow=luckynum;
                    do {
                        luckynum=rand()%bsmDataCnt;
                    } while(!bsmcData[luckynum][0]);
                    fFrame=cham=0;        
                    fpre=bsmFind(luckynum);
                }
                if(bsmFrameNow>=45) {
                    drwHandle(0, 0);
                    bufChange();
                    drwHandle(0, 0);
                    bufChange();
                    bsmRunNow=1;
                }
                else if(bsmFrameNow>=40) drwHandle(1, 0);
                else if(bsmFrameNow>=35) drwHandle(2, 0);
                else if(bsmFrameNow>=30) drwHandle(3, 0);
                else if(bsmFrameNow>=25) drwHandle(4, 0);
                else if(bsmFrameNow>=20) drwHandle(5, 0);
                else if(bsmFrameNow>=15) drwHandle(4, 0);
                else if(bsmFrameNow>=10) drwHandle(3, 0);
                else if(bsmFrameNow>=5) drwHandle(2, 0);
                else if(bsmFrameNow>=0) drwHandle(1, 0);
            }
            if(bsmRunNow<2) {
                drwSlot(0, fFrame+1, bsmiData[fnow][0], bsmiData[fnow][1], bsmiData[fnow][2]);
                drwSlot(0, fFrame-8, bsmiData[fpre][0], bsmiData[fpre][1], bsmiData[fpre][2]);
            }
            else {
                drwSlot(0, 0, bsmiData[luckynum][0], bsmiData[luckynum][1], bsmiData[luckynum][2]);
            }
            if(bsmRunNow<3) {
                drwSlot(1, fFrame+1, bsmiData[fnow][3], bsmiData[fnow][4], bsmiData[fnow][5]);
                drwSlot(1, fFrame-8, bsmiData[fpre][3], bsmiData[fpre][4], bsmiData[fpre][5]);
            }
            else {
                drwSlot(1, 0, bsmiData[luckynum][3], bsmiData[luckynum][4], bsmiData[luckynum][5]);
            }
            if(bsmRunNow<4) {
                drwSlot(2, fFrame+1, bsmiData[fnow][6], bsmiData[fnow][7], bsmiData[fnow][8]);
                drwSlot(2, fFrame-8, bsmiData[fpre][6], bsmiData[fpre][7], bsmiData[fpre][8]);
            }
            if(fFrame>=9) {
                fnow=fpre;
                if(fnow==luckynum) {
                    bsmRunNow++;
                }
                if(cham<BSM_CHAM_MAX) {
                    fpre=bsmFind(fnow);
                    cham++;
                }
                else {
                    fpre=luckynum;
                    cham=0;
                }
                fFrame=0;
            }
            if(bsmRunNow>3) {
                bsmIsAct=0;
                bsmRunNow=-1;
                readIsAct=1;
                drwSlot(2, 0, bsmiData[luckynum][6], bsmiData[luckynum][7], bsmiData[luckynum][8]);
                sprintf(tt, "%s님, 당첨을 축하드립니다!     ", bsmcData[luckynum]);
                drwAlarm(tt);
                bufChange();
                drwAlarm(tt);
                bufChange();
                bsmcData[luckynum][0]=0;
            }
            fFrame++;
        }
        bsmCurTime = clock();
        if(20-bsmCurTime+bsmOldTime>0)
            Sleep(20-bsmCurTime+bsmOldTime);
        bufChange();
    }
    bufRel();
}