/*==========================================================================
 * Name:23.c
 * Author : Adithi P
 * Description :  Write a program to print the maximum number of files can be opened within a process and  
size of a pipe (circular buffer).
 * Date: 18th September,2025
 * =========================================================================*/
#include<unistd.h>
#include<stdio.h>

int main(void){
	long PIPE_BUF,OPEN_MAX;
	PIPE_BUF=pathconf(".",_PC_PIPE_BUF);
	OPEN_MAX=sysconf(_SC_OPEN_MAX);
	printf("Maximum number of files openable %ld \t size of pipe(circular buffer) %ld \n");
}
/*=============================================================================
 * Output 
 * adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Maximum number of files openable 7       size of pipe(circular buffer) 0 
// No issues with size od pipe = 0 as no limit exists 
// */
