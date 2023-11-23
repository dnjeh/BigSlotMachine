#include "../fixing.h"

int readIsAct=1;

unsigned __stdcall readChar(void *arg) {
    char t;
    while(1) {
        t=_getch();
        if(readIsAct) {
            if(t==13) {
                readIsAct=0;
                bsmIsAct=1;
            }
            else if(t=='z') {
                bsmIsRmName=!bsmIsRmName;
            }
            else if(t=='x') {
                bsmIsRealRand=!bsmIsRealRand;
            }
        }
    }
}