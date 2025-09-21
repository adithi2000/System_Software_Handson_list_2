/*==================================================================
 * Name : 12.c
 * Author : Adithi P
 * Description:  Write a program to create an orphan process. Use kill system call to send SIGKILL signal to 
the parent process from the child process.
 * Date: 20th September,2025
 * ====================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>


int main(void){
	if(!fork()){
		printf("In the child process \n");
		printf("initial ppid is %d \n",getppid());
		printf("Child: Sending SIGKILL to parent...\n");
        	kill(getppid(), SIGKILL);
		sleep(10);
		printf("the ppid now is %d \n",getppid());
	}
	else{
		printf("My pid as a parent is %d \n",getpid());
	}
		
}
/*====================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ cc 12.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
My pid as a parent is 1153
In the child process
initial ppid is 1153
Child: Sending SIGKILL to parent...
adithi@DESKTOP-B2HISG8:~/handson_2$ the ppid now is 348*/

