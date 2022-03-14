#include "stdio.h"
#include "stdlib.h"
#include "unistd.h"
#include "mastermind.h"


void my_putchar(char c);
void my_putstr(char *param_1);
int checkRI(char *buf);
void getInput();
int wellP();
int missedP();

void myMastermind(char *code, int attempts){
    int i;
    
    my_putstr("Will you find the secret code?\n---\n");

    for(i =0;i<attempts;i++) {
        char buf[20];
        getInput(i,buf);
        if(wellP(code,buf) == 4) {
            my_putstr("Congratz! You did it!\n");
            i =-1;   
            break;
        }
            printf("Well placed pieces: %d\nMisplaced pieces: %d\n---\n", wellP(code, buf), missedP(code, buf) - wellP(code, buf));
    }

    if(i!=-1)      
        my_putstr("You lose it!\n");
}



void my_putchar(char c)
{
    write(1, &c, 1);
}


void my_putstr(char *param_1)
{
    for(int i = 0;param_1[i] != '\0';i++){
        my_putchar(param_1[i]);
    }
}


int checkRI(char *buf)
{
    for(int i = 0;i < 4; i++){
        if(buf[i]<48 || buf[i] >55)
            return 0;
    }
    return 1;
}

void getInput(int i, char *buf){
        printf("Round %d \n", i);
        while(1){
            int ret;
            my_putstr(">");
            ret = read(0,buf, 20);//scanf("%s", buf);
            if (checkRI(buf) && ret<6)    
             break;     
                my_putstr("Wrong input!\n");
        }
}

int wellP(char *code, char* buf){
    int WP = 0;
    for(int j =0;j < 4;j++)
            if(code[j]==buf[j])
                 WP++;
    
    return WP;
}

int missedP(char *code, char *buf){
    int MP = 0;
     for(int j =0;j < 4;j++){
         int c = 1;
         for(int k = 0;k<4;k++)
                if(code[j] == buf[k] && c){
                          MP++;
                          c = 0;
                }
     }
        return MP;
}