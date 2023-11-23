#include "../fixing.h"

char pahCon[20] = "config.txt";
char pahCsv[20]={'\0', };
char pahLog[20]={'\0', };
char pahRes[20]={'\0', };

void pahInit() {
    fp=fopen(pahCon, "r");     
    fgets(pahCsv, sizeof(pahCsv), fp);
    rmEnt(pahCsv);
    fgets(pahLog, sizeof(pahLog), fp);
    rmEnt(pahLog);
    fgets(pahRes, sizeof(pahRes), fp);
    rmEnt(pahRes);
    fclose(fp);
}