#ifndef HELPER_H
#define HELPER_H 

#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isValidNumber(const char* str) {
    for(int i=0;i<strlen(str);i++) {
        if(str[i] < '0' || str[i] > '9') return false;
    }
    return true;
}
int getNumber(const char* prompt) {
    char buf[101];
    while(true) {
        printf("%s", prompt);
        fgets(buf, 100, stdin);
        buf[strlen(buf)-1] = 0;
        if(isValidNumber(buf)) {
            return atoi(buf);
        }
        printf("invalid input\n");
    }
}

#endif 