/*==================================================================
 * Name : 9.c
 * Author : Adithi P
 * Description: Write a program to ignore a SIGINT signal then reset the default action of the SIGINT 
signal -  Use signal system call.  
 * Date: 20th September,2025
 * ====================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>

int main(void){
	 signal(SIGINT, SIG_IGN);
	printf("Ignoring SIGINT\n");
 	sleep(5);
 	printf("No SIGINT in 5 seconds \n");
 	signal(SIGINT, SIG_DFL);
	 printf("Default action for SIGINT\n");
 	sleep(5);
 	printf("No SIGINT within 5 seconds\n");

}
/*====================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 9.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 9.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Ignoring SIGINT
^C
No SIGINT in 5 seconds
Default action for SIGINT
^C */

