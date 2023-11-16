#include <stdio.h>
#include <Windows.h>
#include <process.h>

unsigned __stdcall Thread_1(void *arg) {
    while (1) {
        printf("thread1\n");
        Sleep(1000);
    }
}

int main() { 
    _beginthreadex(NULL, 0, Thread_1, 0, 0, NULL);
    while(1) {
        printf("main\n");
        Sleep(500);
    }
    return 0;
}