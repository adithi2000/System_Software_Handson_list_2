/*==================================================================
 * Name : 11.c
 * Author : Adithi P
 * Description: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT signal -  
use sigaction system call 
 * Date: 20th September,2025
 * ====================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>


int main(void){
	struct sigaction sa;
        sa.sa_handler=SIG_IGN;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags=0;
        sigaction(SIGINT, &sa, NULL);
	printf("Ignoring SIGINT \n");
	sleep(3);
	sa.sa_handler=SIG_DFL;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags=0;
        sigaction(SIGINT, &sa, NULL);
        printf("DEFAULT HANDLER SIGINT \n");
        sleep(3);
}
/*====================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 11.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 11.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Ignoring SIGINT
^C
DEFAULT HANDLER SIGINT
^C */

