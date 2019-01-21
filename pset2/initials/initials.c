#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>



int main(void){
    string name = get_string();
    
    if(name == NULL)
        return -1;
        
        
    if(name[0] != ' '){
        printf("%c", toupper(name[0]));
    }
        
    for(int i=1; i<strlen(name); i++){
       if(name[i-1] == ' ' && name[i] != ' '){
           
        printf("%c", toupper(name[i]));
       }
    }
    
    
    printf("\n");
}