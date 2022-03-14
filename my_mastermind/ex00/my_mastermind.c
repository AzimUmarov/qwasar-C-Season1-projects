#include "stdio.h"	
#include "time.h"	
#include "stdlib.h"	
#include "mastermind.h"	

void writeInArray(char *av,char *code);	
void createRandomNumber(char *code);	
int  checkIn(char* attempts);	


int main(int ac, char **av){	
    char code[5];	
    int attempts = 10, errorCode = 0;	
    createRandomNumber(code);	
    	
     for(int i =1 ;i<ac;i++){	
         if(av[i][1] == 'c'){	
             if(checkRI(av[i+1-(i+1==ac)]) && i+1<ac)     writeInArray(av[i+1],code);	
             else                                  errorCode = 1; 	
         }	
         if(av[i][1] == 't'){	
             if(checkIn(av[i+1-(i+1==ac)]) && i+1<ac)       attempts = atoi(av[i+1]);	
             else                                  errorCode = 1; 	
         }       	
     }	
    	
    if(errorCode == 0)                                   myMastermind(code,attempts);	
    else                             my_putstr("Invalid secret code or attempts \n");	
    
    return 0;	
}	

void writeInArray(char *av,char *code){	
    for(int i =0;i<4;i++){	
          code[i] = av[i];	
    }	

          code[4] = '\0';	
}	


int  checkIn(char* attempts){	
    for(int i =0;attempts[i] != '\0';i++)	
       if(attempts[i]<48 || attempts[i]>57)	
                return 0;	
        return 1;	
            	
}	

void createRandomNumber(char *code){	
       srand(time(0));	
      for (int i = 0; i < 4; i++)	
            code[i] = (rand() % 8) + 48;	
        code[4] = '\0';	
}