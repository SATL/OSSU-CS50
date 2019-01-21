#include <stdio.h>
#include <cs50.h>
#include <string.h>
#define _GNU_SOURCE
#include <crypt.h>

void crack(string hash){
    char salt[3]= {hash[0], hash[1], '\0'};
    printf("%s\n", salt);
    
    for(int i=65; i<123; ++i){
        char test[5];
        test[0]=(char) i;
        test[1] = '\0';
        string cracked = crypt(test, salt);
        if(strcmp(cracked, hash) == 0){
            printf("%s", test);
            return;
        }
        for(int j=65; j<123; ++j){
            test[1] = (char) j;
            test[2] = '\0';
            cracked = crypt(test, salt);
            if(strcmp(cracked, hash) == 0){
                printf("%s", test);
                return;
            }
            for(int k=65; k<123; ++k){
                test[2] = (char) k;
                test[3] = '\0';
                cracked = crypt(test, salt);
                printf("%s = %s\n", test, cracked);
                if(strcmp(cracked, hash) == 0){
                    printf("%s", test);
                    return;
                }
                for(int l=65; l<123; ++l){
                    test[3] = (char) l;
                    test[4] = '\0';
                    cracked = crypt(test, salt);
                    printf("%s = %s\n", test, cracked);
                    if(strcmp(cracked, hash) == 0){
                        printf("%s", test);
                        return;
                    }
                }
            }
            
        }
    }
}

int main(int argc, string args[]){
    
    if(argc == 1 || argc >2){
        printf("Usage: ./crack hash \n");
        return 1;
    }
    
    string hash = args[1];
    printf("hash: %s\n", args[1]);
    crack(hash);
}