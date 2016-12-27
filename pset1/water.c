#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void nainAtoi(const char* numArray, int *value)
{
    int i;
    const int len = strlen(numArray)-1;

    for (i = 0; i < len; i++)
    {
        if (!isdigit(numArray[i])) break;
    }
    *value = len == i ? atoi(numArray) : 0;
}

int getfNumber(){
    char message[30];
    int val;
    fgets(message, 30, stdin);
    nainAtoi(message, &val);
    if(val<=0){
        printf("Retry: ");
        return getfNumber();
    }
    return val;
}

int main(void)
{
    
    printf("minutes: ");
    int minutes = getfNumber();
    printf("%d\n", minutes*12);
}