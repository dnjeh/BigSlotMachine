#include "fixing.h"
//gcc -fdiagnostics-color=always -g .\main.c .\fixing.c .\src\buffer.c .\src\path.c -o bsm.exe -lm
int main() {
    char t;
    int i, j;
    system("mode con cols=100 lines=45");
    system("chcp 65001");
    system("cls");
    
    pahInit();
    bufInit();
    drwInit();
    while(1) {
        t=_getch();
        Sleep(20);
    }
    bufRel();
}