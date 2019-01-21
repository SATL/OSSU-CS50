#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>



int main(int argc, string args[]){
    if(argc !=2){
        printf("Usage: ./vigenere k");
        return 1;
    }
    string key = args[1];
    int key_length = strlen(key);
    for(int i = 0; i < key_length; i++)
    {
        if (!isalpha(key[i]))
        {   
            printf("Non-alphabetic characters given. Aborting.\n");
            return 1;
        }
    }
        
    printf("plaintext: ");
    
    string text = get_string();
    
    printf("ciphertext: ");
    int skip = 0;
    
    for(int i=0; i<strlen(text); i++){
        char item = text[i];
        int keyi =  i-skip;
        if(i>=key_length)
            keyi = (i-skip) % key_length;
        char valkey = toupper(key[keyi])-65;
            
        int toSum = isupper(text[i]) ? 65:97;
       
            if(islower(item)){
                
                printf("%c", (((item -toSum) +valkey) %26)+toSum);
            }
                
            else if(isupper(item)){
                
                printf("%c", (((item -toSum) +valkey) %26)+toSum);
            }
            
            else{
                printf("%c", item);
                ++skip;
            }
    }
    
    printf("\n");
    
}