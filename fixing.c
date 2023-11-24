#include "fixing.h"

HANDLE buf[2];
FILE *fp=NULL, *fp2=NULL;
int bsmDataCnt=0;
int bsmiData[100][9]={{0,}};
char bsmcData[100][50]={{'\0',}};

int bsmIsAct=0;
int bsmIsRealRand=0;
int bsmIsRmName=1;
int bsmFrameNow=0;

void bsmInit() {
    int i, j;
    char t[100], tt[100];
    fp=fopen(pahCsv, "r");
    for(i=0;!feof(fp);i++) {
        fscanf(fp, "%s,", bsmcData[i]);
        for(j=0;j<8;j++) {
            fscanf(fp, "%d,", &bsmiData[i][j]);
        } fscanf(fp, "%d\n", &bsmiData[i][8]);
    } bsmDataCnt=i;
    fclose(fp);
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