/*==================================================================================
 * Name: 13b.c
 * Author : Adithi P
 * Description:  Write two programs: first program is waiting to catch SIGSTOP signal, the second program 
		will send the signal (using kill system call). Find out whether the first program is able to catch 
		the signal or not
  * Date: 20th September,2025
  * ===============================================================================*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

//kill sender program
int main(int argc,char *argv[]){
	if(argc != 2){
		perror("No 2 args sent");
	}
	pid_t pid = atoi(argv[1]);
        kill(pid,SIGSTOP);
}
