#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdint.h>
#include <limits.h>


void my_putchar(char c);
void my_putstr(char *param_1);
char *mstr(char *str);
char* printp(void *thing);
char * printNumber(long long i, char *strout, int b);
int my_printf(char * str, ...);

int main(){

    //your test space my dear peer reviewer! please read README.md file

}

int my_printf(char * str, ...){
    va_list c;
    int i = 0, j = 0;
    char buff[1000] = {0}, tmp[200];
    char *strarg;

    va_start(c, str);
    while (str && str[i] != '\0') {
        if(str[i] == '%'){
            i++;
            switch (str[i]) {
                case 'c': {
                    buff[j] = (char) va_arg(c, int);
                    j++;
                    break;
                }
                case 'u':{
                    long long i = va_arg(c, int);
                    long long t = 4294967296;
                    if(i<0){
                        i = t + i;
                    }
                    printNumber(i, tmp, 10);
                    strcpy(&buff[j], tmp);
                    j += strlen(tmp);
                    break;
                }
                case 'd':
                case 'i':{
                    printNumber(va_arg(c, int), tmp, 10);
                    strcpy(&buff[j], tmp);
                    j += strlen(tmp);
                    break;
                }
                case 'p': {
                    strarg = printp(va_arg( c, char* ));
                    strcpy(&buff[j], strarg);
                    j += strlen(strarg);
                    break;
                }
                case 'x': {
                    printNumber(va_arg(c, int), tmp, 16);
                    strcpy(&buff[j], tmp);
                    j += strlen(tmp);
                    break;
                }
                case 'o': {
                    printNumber(va_arg(c, int), tmp, 8);
                    strcpy(&buff[j], tmp);
                    j += strlen(tmp);
                    break;
                }
                case 's': {
                    strarg = va_arg(c, char* );
                    if(!strarg || !*strarg) {
                        strcpy(&buff[j], "(null)");
                        j += 6;
                    }
                    else {
                        strcpy(&buff[j], strarg);
                        j += strlen(strarg);
                    }
                    break;
                }
                default:{
                    my_putstr("Error input !\n");
                    return j;
                }
            }
        } else {
            buff[j] = str[i];
            j++;
        }
        i++;
    }
    write(STDOUT_FILENO, buff, j);
    va_end(c);
    return j;
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

char *mstr(char *str){
    int i;
    int len = 0;
    char c;
    if (!str)
        return NULL;
    while(str[len] != '\0'){
        len++;
    }
    for(i = 0; i < (len/2); i++)
    {
        c = str[i];
        str [i] = str[len - i - 1];
        str[len - i - 1] = c;
    }
    return str;
}


char* printp(void *thing) {
    uintptr_t j = (uintptr_t) thing;
    char lst[(sizeof j * CHAR_BIT + 3)/ 4 + 1]; // Size needed to print in base 16
    char *p = &lst[sizeof lst] - 1;
    *p = '\0';
    do {
        p--;
        *p = "0123456789abcdef"[j%16];
        j /= 16;
    } while (p > lst);
    char *r;
    r= (char*)malloc(28*sizeof(char*));
    r[0] = '0';
    r[1] = 'x';
    for(int i = 2; p[i] !='\0'; i++){
        r[i] = p[i+2];
    }
    return r;

}

char * printNumber(long long i, char *strout, int b){

    char *str = strout;
    if(i==0){
        *strout = '0';
        strout[1] = '\0';
        return 0;
    }
    int digit, sign = 0;
    if (i < 0) {
        sign = 1;
        i *= -1;
    }
    while(i) {
        digit = i % b;
        *str = (digit > 9) ? ('A' + digit - 10) : '0' + digit;
        i = i / b;
        str ++;
    }
    if(sign)
        *str++ = '-';

    *str = '\0';
    mstr(strout);
    return strout;
}
