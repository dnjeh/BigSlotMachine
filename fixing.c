#include "fixing.h"

HANDLE buf[2];
FILE *fp=NULL, *fp2=NULL;
int bsmDataCnt=0;
int bsmiData[100][15]={{0,}};
char bsmcData[100][50]={{'\0',}};

int bsmIsAct=0;
int bsmIsRealRand=0;
int bsmIsRmName=1;
int bsmFrameNow=0;

void bsmInit() {
    int i, j, f=0, it;
    char t[100];
    fp=fopen(pahCsv, "r");
    for(i=0;!feof(fp);i++) {
        fgets(t, sizeof(t), fp);
        for(f=j=0;t[j]!='\n';j++) {
            if(t[j]==',') {
                if(f) {
                    bsmiData[i][f-1]=it;
                }
                f++;
                it=0;
            }
            else {
                if(!f) {
                    bsmcData[i][j]=t[j];
                } 
                else {
                    it=it*10+t[j]-48;
                }
            }
        } bsmiData[i][f-1]=it;
    } bsmDataCnt=i;
    fclose(fp);
    srand(time(NULL));
}

int bsmFind(int sta) {
    int ret=sta+1;
    for(ret%=bsmDataCnt;;ret=(ret+1)%bsmDataCnt) {
        if(bsmcData[ret][0]) {
            return ret;
        }
    }
    return 0;
}

void rmEnt(char *str, int siz) {
    int i;
    for(i=0;str[i]!='\0'&&i<siz;i++) {
        if(str[i]=='\n') {
            str[i]='\0';
            return;
        }
    }
}