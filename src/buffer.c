#include "../fixing.h"

int bufNow=0;

void bufChange() {
    SetConsoleActiveScreenBuffer(buf[bufNow]);
    bufNow=!bufNow;
}
void bufInit() {
    int i, j;
    char temp[20]="", temp2[70]="";
    CONSOLE_CURSOR_INFO cci;
    COORD Coor = {SLOT_INIT_X, SLOT_INIT_Y};
    DWORD dw;
    //버퍼 생성
    buf[0] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    buf[1] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
    cci.dwSize = 1;
    cci.bVisible = 0;
    SetConsoleCursorInfo(buf[0], &cci);
    SetConsoleCursorInfo(buf[1], &cci);
    //버퍼 기본 작성
    strcpy(temp, pahRes);
    strcat(temp, "/machine/slot.txt");
    fp=fopen(temp, "r");     
    for(i=0;i<SLOT_SIZ_Y;i++) {
        fgets(temp2, sizeof(temp2), fp);
        rmEnt(temp2, sizeof(temp2));
        Coor.Y=i+SLOT_INIT_Y;
        for(j=0;j<2;j++) {
            SetConsoleCursorPosition(buf[j], Coor);
            WriteFile(buf[j], temp2, strlen(temp2), &dw, NULL);        
        }
    }
    fclose(fp);
    bufChange();
}
void bufRel() {
    CloseHandle(buf[0]);
    CloseHandle(buf[1]);
}