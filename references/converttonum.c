#include <stdio.h>
#include <conio.h>
const int debug=0;
int main() {
    char t, tt;
    if(debug) {
        while(t!=EOF) {
            t=_getch();
            printf("%d %c\n", t, t);
        }
    }
    while(t!=EOF) {
        t=_getch();
        if(t!=13) {
            if(t=='q') {
                tt=_getch();
                if(tt=='t') printf("30");
                else if(tt=' ') printf("6");
            }
            else if(t=='Q') printf("17");
            else if(t=='w') printf("9");
            else if(t=='W') printf("19");
            else if(t=='e') printf("3");
            else if(t=='E') printf("16");
            else if(t=='r') {
                tt=_getch();
                if(tt=='t') printf("20");
                else if(tt=' ') printf("1");
            }
            else if(t=='R') printf("15");
            else if(t=='t') printf("7");
            else if(t=='T') printf("18");
            else if(t=='a') printf("5");
            else if(t=='s') {
                tt=_getch();
                if(tt=='w') printf("21");
                else if(tt=='g') printf("22");
                else if(tt==' ') printf("2");
            }
            else if(t=='d') printf("8");
            else if(t=='f') {
                tt=_getch();
                if(tt=='r') printf("23");
                else if(tt='a') printf("24");
                else if(tt='q') printf("25");
                else if(tt='t') printf("26");
                else if(tt='x') printf("27");
                else if(tt='v') printf("28");
                else if(tt='g') printf("29");
                else if(tt=' ') printf("4");
            }
            else if(t=='g') printf("14");
            else if(t=='z') printf("11");
            else if(t=='x') printf("12");
            else if(t=='c') printf("10");
            else if(t=='v') printf("13");

            else if(t=='y') printf("11");
            else if(t=='u') printf("7");
            else if(t=='i') printf("3");
            else if(t=='o') printf("2");
            else if(t=='O') printf("4");
            else if(t=='p') printf("6");
            else if(t=='P') printf("8");
            else if(t=='h') {
                tt=_getch();
                if(tt=='k') printf("15");
                else if(tt='o') printf("16");
                else if(tt='l') printf("17");
                else if(tt=' ') printf("10");
            }
            else if(t=='j') printf("5");
            else if(t=='k') printf("1");
            else if(t=='l') printf("9");
            else if(t=='b') printf("13");
            else if(t=='n') {
                tt=_getch();
                if(tt=='j') printf("18");
                else if(tt='p') printf("19");
                else if(tt='l') printf("20");
                else if(tt=' ') printf("12");
            }
            else if(t=='m') {
                tt=_getch();
                if(tt=='l') printf("21");
                else if(tt=' ') printf("14");
            }
            else if(t==' ') printf("0");
            printf(",");
        }
        else printf("\n");
    }
}