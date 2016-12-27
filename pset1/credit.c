#include <stdio.h>
#include <cs50.h>
#include <math.h>


long long getCard(){
    long long card = GetLongLong();
    return card;
}


int getLDigit(const long long number, const int position){
    double base = 10;
    long long base1 = pow(base, position);
    long long base2 = pow(base, position-1);

    long long value = number%base1 / base2;
    return (int) value;
}

int getDigitSum(const int digit){
  double length = floor (log10 (abs (digit))) + 1;
  int total = 0;
  for(int i=0; i<length; i++){
      total+=getLDigit((long long) digit, i+1);
  }
  
  return total;
    
}

int getSecondMult(const long long card, const double length){
    int odd=0;
    int total2 = 0;
    int total1 = 0;
    for(int i= (int) length-1; i>=0; i--, odd++){
        if(odd%2!=0){
            int digit = getLDigit(card, i+1);
            total2+= digit<5?digit*2:getDigitSum(digit*2);
        }else{
            total1+=getLDigit(card, i+1);
        }
    }
    return total2+total1;
}

int getStart(long long card, double length){
    int first = getLDigit(card, length);
    int second = getLDigit(card, length-1);
    return first*10+second;
}

void setType(int start){
    switch (start){
        case 34:
        case 37:
            printf("AMEX\n");
            break;
        case 51:
        case 52:
        case 53:
        case 54:
        case 55:
            printf("MASTERCARD\n");
            break;
    }
    
    if(start>=40 && start<50)
        printf("VISA\n");
}


int main(void){
    printf("Number: ");
    long long card = getCard();
    double length = floor (log10 (llabs (card))) + 1;
    if(length<11 || length >16){
        printf("INVALID\n");
        return 0;
    }
    
    
    int start = getStart(card, length);
    setType(start);
    /* Check sum valid algorithm
    int sum =  getSecondMult(card, length);;
    
    if(sum%10 == 0)
        printf("Valid \n");
    else
        printf("Invalid \n");*/
}