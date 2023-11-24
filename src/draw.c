#include "../fixing.h"

int drwIsLet[7][4][31]={{{0,},},};
char drwLet[7][4][31][9][20]={{{{{'\0',},},},},};
char drwCHandle[SLOT_HANDLE_SIZ_Y][SLOT_HANDLE_SIZ_X+5]={{'\0',},};
char drwCHandleBall[2][SLOT_HANDLE_BALL_SIZ_Y][SLOT_HANDLE_BALL_SIZ_X+6]={{'\0',},};

void drwInit() {
    char tpath[30];
    int i, j, k, l, m, kmax;

    for(k=0;k<=1;k++) {
        sprintf(tpath, "%s/letter/%d/%d/%d.txt", pahRes, 0, 0, k);
        if((fp=fopen(tpath, "r"))!=NULL) {
            drwIsLet[0][0][k]=1;
            for(l=0;l<LET_MAX_Y;l++) {
                fgets(drwLet[0][0][k][l], sizeof(drwLet[0][0][k][l]), fp);
                rmEnt(drwLet[0][0][k][l], sizeof(drwLet[0][0][k][l]));
            }
            fclose(fp);
        }
    }
    for(i=1;i<=6;i++) {
        for(j=1;j<=(i>3?3:2);j++) {
            if(j==1) kmax=LET_JA_MAX;
            else if(j==3) kmax=LET_JAJA_MAX;
            else switch (i) {
            case 1: case 4: 
                kmax=LET_14_MO_MAX;
                break;
            case 2: case 5: 
                kmax=LET_14_MO_MAX+LET_25_MO_MAX;
                break;
            case 3: case 6: 
                kmax=LET_14_MO_MAX+LET_25_MO_MAX+LET_36_MO_MAX;
                break;
            }
            for(k=1;k<=kmax;k++) {
                sprintf(tpath, "%s/letter/%d/%d/%d.txt", pahRes, i, j, k);
                if((fp=fopen(tpath, "r"))!=NULL) {
                    drwIsLet[i][j][k]=1;
                    for(l=0;l<LET_MAX_Y;l++) {
                        fgets(drwLet[i][j][k][l], sizeof(drwLet[i][j][k][l]), fp);
                        rmEnt(drwLet[i][j][k][l], sizeof(drwLet[i][j][k][l]));
                    }
                    fclose(fp);
                }
            }
        }
    }
    sprintf(tpath, "%s/machine/handle.txt", pahRes);
    fp=fopen(tpath, "r");     
    for(i=0;i<SLOT_HANDLE_SIZ_Y;i++) {
        fgets(drwCHandle[i], sizeof(drwCHandle[i]), fp);
        rmEnt(drwCHandle[i], sizeof(drwCHandle[i]));
    }
    fclose(fp);
    for(j=1;j<=2;j++) {
        sprintf(tpath, "%s/machine/handle_ball%d.txt", pahRes, j);
        fp=fopen(tpath, "r");     
        for(i=0;i<SLOT_HANDLE_SIZ_Y;i++) {
            fgets(drwCHandleBall[j-1][i], sizeof(drwCHandleBall[j-1][i]), fp);
            rmEnt(drwCHandleBall[j-1][i], sizeof(drwCHandleBall[j-1][i]));
        }
        fclose(fp);
    }
}

void drwBuf(int y, int x, char *str) {
    COORD Coor = {x, y};
    DWORD dw;
    SetConsoleCursorPosition(buf[bufNow], Coor);
    WriteFile(buf[bufNow], str, strlen(str), &dw, NULL);    
}

void drwHandle(int dy, int f) {
    int i, j, y, x;
    char t[10]="         ";
    for(i=0;i<SLOT_HANDLE_SIZ_Y;i++) {
        drwBuf(i+SLOT_HANDLE_Y, SLOT_HANDLE_X, drwCHandle[i]);
    }
    for(i=0;i<dy;i++) {
        drwBuf(i+SLOT_HANDLE_BALL_Y, SLOT_HANDLE_BALL_X, t);        
    }
    for(i=0;i<SLOT_HANDLE_BALL_SIZ_Y;i++) {
        drwBuf(i+SLOT_HANDLE_BALL_Y+dy, SLOT_HANDLE_BALL_X, drwCHandleBall[f][i]);
    }
}

void drwConfig() {
    int i, j;
    char temp[50]={'\0'};

    sprintf(temp, "> %s: %s (%d행)", "원본 파일 이름", pahCsv, bsmDataCnt);
    drwBuf(CON_LINE0_Y, CON_LINE_X, temp);
    sprintf(temp, "> %s: %s", "로그 파일 이름", pahLog);
    drwBuf(CON_LINE1_Y, CON_LINE_X, temp);
    sprintf(temp, "> %s       (%c)", "당첨된 사람 삭제하기", bsmIsRmName?'o':'x');
    drwBuf(CON_LINE2_Y, CON_LINE_X, temp);
    sprintf(temp, "> %s             (%c)", "완전 랜덤 모드", bsmIsRealRand?'o':'x');
    drwBuf(CON_LINE3_Y, CON_LINE_X, temp);
}

void drwAlarm(char *str) {
    char temp[50]={'\0'};
    
    sprintf(temp, "> %s", str);
    drwBuf(DRW_ALARM_Y, DRW_ALARM_X, temp);
}

void drwSlot(int sind, int dy, int t, int tt, int ttt) {
    int x, y=SLOT_SLOT_Y;
    if(!sind) {
        x=SLOT_SLOT0_X;
    }
    else if(sind==1) {
        x=SLOT_SLOT1_X;
    }
    else if(sind==2) {
        x=SLOT_SLOT2_X;
    }
    if(!t) {
        drwAreaSlot(y+dy, x, t, tt, ttt);
    }
    else if(t<=LET_JA_MAX&&tt<=LET_14_MO_MAX&&!ttt) {
        drwAreaSlot(y+dy, x, 1, 2, tt);
        drwAreaSlot(y+dy, x, 1, 1, t);
    }
    else if(t<=LET_JA_MAX&&tt<=LET_25_MO_MAX+LET_14_MO_MAX&&!ttt) {
        drwAreaSlot(y+dy, x, 2, 2, tt);
        drwAreaSlot(y+dy, x, 2, 1, t);
    }
    else if(t<=LET_JA_MAX&&tt<=LET_14_MO_MAX+LET_25_MO_MAX+LET_36_MO_MAX&&!ttt) {
        drwAreaSlot(y+dy, x, 3, 2, tt);
        drwAreaSlot(y+dy, x, 3, 1, t);
    }
    else if(t<=LET_JA_MAX&&tt<=LET_14_MO_MAX&&ttt<=LET_JAJA_MAX) {
        drwAreaSlot(y+dy, x, 4, 3, ttt);
        drwAreaSlot(y+dy, x, 4, 2, tt);
        drwAreaSlot(y+dy, x, 4, 1, t);
    }
    else if(t<=LET_JA_MAX&&tt<=LET_25_MO_MAX+LET_14_MO_MAX&&ttt<=LET_JAJA_MAX) {
        drwAreaSlot(y+dy, x, 5, 3, ttt);
        drwAreaSlot(y+dy, x, 5, 2, tt);
        drwAreaSlot(y+dy, x, 5, 1, t);
    }
    else if(t<=LET_JA_MAX&&tt<=LET_14_MO_MAX+LET_25_MO_MAX+LET_36_MO_MAX&&ttt<=LET_JAJA_MAX) {
        drwAreaSlot(y+dy, x, 6, 3, ttt);
        drwAreaSlot(y+dy, x, 6, 2, tt);
        drwAreaSlot(y+dy, x, 6, 1, t);
    }
    else {
        drwAreaSlot(y+dy, x, 0, 0, 1);
    }
}

void drwAreaSlot(int y, int x, int t, int tt, int ttt) {
    int i, j;
    for(i=0;i<LET_MAX_Y;i++) {
        if(y+i>=SLOT_SLOT_Y+LET_MAX_Y||y+i<SLOT_SLOT_Y) continue;
        if(drwIsLet[t][tt][ttt]) {
            drwBuf(y+i, x, drwLet[t][tt][ttt][i]);
        }
        else {
            drwBuf(y+i, x, drwLet[0][0][1][i]);   
        }
    }
}

void drwFirst() {
    int i;
    for(i=0;i<2;i++) {
        //drwSlot(0, 0, 1, 9, 5);
        //drwSlot(1, 0, 3, 10, 0);
        //drwSlot(2, 0, 8, 18, 2);
        drwSlot(0, 0, bsmiData[0][0], bsmiData[0][1], bsmiData[0][2]);
        drwSlot(1, 0, bsmiData[0][3], bsmiData[0][4], bsmiData[0][5]);
        drwSlot(2, 0, bsmiData[0][6], bsmiData[0][7], bsmiData[0][8]);
        if(bsmDataCnt) {
            drwAlarm("Enter 키를 눌러 운명을 확인하세요!");
        }
        else {
            drwAlarm("파일이 읽어지지 않았습니다!");
        }
        bufChange();
    }
}
