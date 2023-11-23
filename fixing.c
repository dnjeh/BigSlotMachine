#include "fixing.h"

HANDLE buf[2];
FILE *fp=NULL, *fp2=NULL;
int bufNow=0;

void rmEnt(char *str, int siz) {
    int i;
    for(i=0;str[i]!='\0'&&i<siz;i++) {
        if(str[i]=='\n') {
            str[i]='\0';
            return;
        }
    }
}