/*==================================================================
 * Name : 8d.c
 * Author : Adithi P
 * Description: 8. Write a separate program using signal system call to catch the following signals. 
    		    g. SIGPROF (use setitimer system call) 
 * Date: 20th September,2025
 * ====================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>

void handler(int signum);
 
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>

void handler(int signum);

int main(void){
struct itimerval timer;

signal(SIGPROF,handler);

timer.it_value.tv_sec=3;
timer.it_value.tv_usec=0;

timer.it_interval.tv_sec=0;
timer.it_interval.tv_usec=10000;

setitimer(ITIMER_PROF,&timer,NULL);

while(1);

}

void handler(int signum){
        printf("signal caught %d \n",signum);
        exit(0);
}
/*====================================
 * Output:
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 8g.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
signal caught 27
*/

