#include "stdio.h"
#include "string.h"
#include <stdbool.h>

int main(int ac, char **av){

    int myAsc[128];
    for(int i=0;i<128;i++)
        myAsc[i] =0;

    for(int i = 1;i<ac;i++)
        for(size_t j = 0;j< strlen(av[i]);j++)
            myAsc[(int)av[i][j]]++;

    for(int i=0;i<128;i++)
        if(myAsc[i]>0 && i != '"')
        printf("%c:%d\n",i, myAsc[i]);

       return 0;
}