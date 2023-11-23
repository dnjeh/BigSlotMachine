#include "../fixing.h"

int drwIsLet[7][4][31]={{{0,},},};
char drwLet[7][4][31][9][20]={{{{{'\0',},},},},};
char drwCHandle[SLOT_HANDLE_SIZ_Y][SLOT_HANDLE_SIZ_X+5]={{'\0',},};
char drwCHandleBall[2][SLOT_HANDLE_BALL_SIZ_Y][SLOT_HANDLE_BALL_SIZ_X+6]={{'\0',},};

void drwInit() {
    char tpath[30];
    int i, j, k, l, m, kmax;
    for(i=1;i<=6;i++) {
        for(j=1;j<=(i>3?3:2);j++) {
            if(j==1) kmax=LET_JA_MAX;
            else if(j==3) kmax=LET_JAJA_MAX;
            else switch (i) {
            case 1: case 4: 
                kmax=LET_14_MO_MAX;
                break;
            case 2: case 5: 
                kmax=LET_25_MO_MAX;
                break;
            case 3: case 6: 
                kmax=LET_36_MO_MAX;
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

void drwHandle(int dy, int f) {
    int i, j;
    char t[10]="         ";
    CONSOLE_CURSOR_INFO cci;
    COORD Coor = {SLOT_HANDLE_BALL_X, SLOT_HANDLE_BALL_Y};
    DWORD dw;
    Coor.X=SLOT_HANDLE_X;
    for(i=0;i<SLOT_HANDLE_SIZ_Y;i++) {
        Coor.Y=i+SLOT_HANDLE_Y;
        SetConsoleCursorPosition(buf[bufNow], Coor);
        WriteFile(buf[bufNow], drwCHandle[i], strlen(drwCHandle[i]), &dw, NULL);    
    }
    Coor.X=SLOT_HANDLE_BALL_X;
    for(i=0;i<dy;i++) {
        Coor.Y=i+SLOT_HANDLE_BALL_Y;
        SetConsoleCursorPosition(buf[bufNow], Coor);
        WriteFile(buf[bufNow], t, strlen(t), &dw, NULL);        
    }
    for(i=0;i<SLOT_HANDLE_BALL_SIZ_Y;i++) {
        Coor.Y=i+SLOT_HANDLE_BALL_Y+dy;
        SetConsoleCursorPosition(buf[bufNow], Coor);
        WriteFile(buf[bufNow], drwCHandleBall[f][i], strlen(drwCHandleBall[f][i]), &dw, NULL);        
    }
}

void drwConfig() {
    int i, j;
    char temp[50]={'\0'};
    CONSOLE_CURSOR_INFO cci;
    COORD Coor = {CON_LINE_X, 0};
    DWORD dw;

    Coor.Y=CON_LINE0_Y;
    sprintf(temp, "> %s: %s (%d행)", "원본 파일 이름", pahCsv, bsmDataCnt);
    SetConsoleCursorPosition(buf[bufNow], Coor);
    WriteFile(buf[bufNow], temp, strlen(temp), &dw, NULL); 

    Coor.Y=CON_LINE1_Y;
    sprintf(temp, "> %s: %s", "로그 파일 이름", pahLog);
    SetConsoleCursorPosition(buf[bufNow], Coor);
    WriteFile(buf[bufNow], temp, strlen(temp), &dw, NULL); 

    Coor.Y=CON_LINE2_Y;
    sprintf(temp, "> %s       (%c)", "당첨된 사람 삭제하기", bsmIsRmName?'o':'x');
    SetConsoleCursorPosition(buf[bufNow], Coor);
    WriteFile(buf[bufNow], temp, strlen(temp), &dw, NULL); 

    Coor.Y=CON_LINE3_Y;
    sprintf(temp, "> %s             (%c)", "완전 랜덤 모드", bsmIsRealRand?'o':'x');
    SetConsoleCursorPosition(buf[bufNow], Coor);
    WriteFile(buf[bufNow], temp, strlen(temp), &dw, NULL);        
}