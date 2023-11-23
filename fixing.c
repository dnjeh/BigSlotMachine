#include "fixing.h"

HANDLE buf[2];
FILE *fp=NULL, *fp2=NULL;
int bsmDataCnt=0;
int bsmiData[100][9]={{0,}};
char bsmcData[100][20]={{'\0',}};

int bsmIsAct=0;
int bsmIsRealRand=0;
int bsmIsRmName=1;
int bsmFrameNow=0;

void bsmInit() {
    int i, j;
    char t[100], tt[100];
    fp=fopen(pahCsv, "r");
    for(i=0;!feof(fp);i++) {
        fscanf(fp, "%s,", &bsmcData[i]);
        for(j=0;j<8;j++) {
            fscanf(fp, "%d,", &bsmiData[j]);
        } fscanf(fp, "%d\n", &bsmiData[8]);
    } bsmDataCnt=i;
    fclose(fp);
    drwSlot(0, 0, 0, 0, 0);
    drwSlot(1, 0, 0, 0, 0);
    drwSlot(2, 0, 0, 0, 0);
    drwAlarm("Enter 키를 눌러 운명을 확인하세요!");
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