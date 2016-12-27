#include <stdio.h>
#include <cs50.h>

void addSpaces(const int total, const int i){
    int spaces =total-i;
    for(int j=0; j<spaces; ++j){
        printf(" ");
    }
}

void addSquares(const int i){
    for(int j=0; j<i; ++j){
        printf("#");
    }
}

void draw(const int total){
    for(int i=0; i<total; i++){
        addSpaces(total, i+1);
        addSquares(i+1);
        printf("  ");
        addSquares(i+1);
        printf("\n");
    }
}

int main(void){
    printf("Height: ");
    int num;
    do
    {
        printf("Enter a non-negative integer < 24: ");
        num = GetInt();
    }while(num >23 || num <0);
    
    
    draw(num);
    return 0;
}