#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<time.h>

// MY BRAIN MADE SOME SUICIDE ATTEMPTS WHILE TRYING TO UNDERSTAND THE CODE.
// TRIED TO MAKE IT AS UNDERSTANDABLE AS I COULD.

// PERSONALLY I DON'T RECOMMEND THIS CODE.  

// PROCEED LEARNING

char getAscii(char bin[]){
    int c, t=0, i=7;
    while(i>=0){
        t = t+pow(2,7-i)*(bin[i]-'0');
        i--;
    }
    return t;
}

void getBinary(char letter, char bin[]){
    int c, t=0, i=7;
    c = (int)letter;
    while(i>=0){
        t = c%2;
        bin[i] = t+'0';
        c = c/2;
        i--;
    }
}

// THINK TWICE BEFORE READING THE NEXT FEW LINES

void divide(char augdw[], char divisor[], char remainder[]){
    int i, r, l, a, t;
    r = strlen(divisor);
    t = strlen(augdw)-r+1;

    char dividend[18], rem[18];
    
    strncpy(dividend, augdw, r);
    l=0;
    memset(rem, 0, 18);

    while(l<t){
        a = 0;
        memset(rem, 0,18);

        if(dividend[0]==divisor[0]){
            for(int j=0; j<r; j++){
                if(dividend[i]==divisor[i]){
                    rem[a++]='0';
                }else{
                    rem[a++]='1';
                }
            }
            rem[a] = '\0';
            strcpy(dividend, rem);
        }
        else{
            strncpy(dividend, &dividend[1], strlen(dividend)-1);
            dividend[r-1] = '\0';
        }
        int o = strlen(dividend);
        dividend[o] = augdw[l+r];
        dividend[r] = '\0';
        l++;
    }

    strncpy(remainder, dividend, r-1);
    remainder[r-1] = '\0';
}

int main(int argc, char const *argv[])
{
    char inp[126], augdw[1018], cw[1018], rcv_cw[1018], rcvdw[1018], divisor[18], remainder[18], rcv_msg[126], bin[9];
    printf("Enter the string to be sent  (max 125 characters): ");
    fgets(inp, sizeof(inp), stdin); 

    getBinary(inp[0], bin);
    strcpy(augdw, bin);

    for(int i=1; i<strlen(inp); i++){
        getBinary(inp[i], bin);
        strcat(augdw, bin);
    }
    strcat(augdw, "000000000000000");

    printf("\nEnter divisor(generator) : ");
    scanf("%s", divisor);

    divide(augdw, divisor, remainder);
    printf("Remainder is %s\n", remainder);

    strcpy(cw, augdw);
    strcat(cw, remainder);

    strcat(rcv_cw, cw);
    printf("\nCodeword to be sent  : %s\n", cw);


    printf("\n-----ERROR GENERATION-----\n");
    int err = 0;
    printf("Enter number of errors to be generated : ");
    scanf("%d", &err);
    srand(time(0));
    
    int k=0;
    for(int j=0; j<err; j++){
        k = rand()%strlen(rcv_cw)-1;
        if(rcv_cw[k]=='0') rcv_cw[k]='1';
        else rcv_cw[k] = '0';
        printf("Error generated at %d bit, %d letter\n", k, k/8+1);
    }

    printf("\n-----RECEIVER SIDE-----\n");
    divide(rcv_cw, divisor, remainder);

    if(strcmp(remainder, "000000000000000")!=0){
        printf("Erroneous data received.\n");
    }

    strncpy(rcvdw, rcv_cw, strlen(rcv_cw)-16);
    rcvdw[strlen(rcv_cw)-16]='\0';
    char letter;
    for(int j=0, k=0; j<strlen(rcvdw); j+=8){
        strncpy(bin, &rcvdw[j], 8);
        bin[8] = '\0';
        letter = getAscii(bin);
        rcv_msg[k++] = letter;
    }
    rcv_msg[k] = '\0';
    
    printf("Received Message : %s", rcv_msg);
    printf("\nEND\n");
    return 0;
}
