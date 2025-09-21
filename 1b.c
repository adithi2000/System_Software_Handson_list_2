/*==================================================================================
 * Name : 1b.c
 * Author : Adithi P
 * Description :
 *  Write a separate program (for each time domain) to set a interval timer in 10sec and
10micro second
       a. ITIMER_VIRTUAL
  * Date: 20th September,2025
* ==================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>

void handler(int signum);

int main(void){
struct itimerval timer;

signal(SIGVTALRM,handler);

timer.it_value.tv_sec=3;
timer.it_value.tv_usec=0;

timer.it_interval.tv_sec=0;
timer.it_interval.tv_usec=10;

setitimer(ITIMER_VIRTUAL,&timer,NULL);

while(1);

}

void handler(int signum){
	printf("Alaram signal caught %d \n",signum);
	exit(0);
}
/*================================================
 * Output
  adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Alaram signal caught 26*/
