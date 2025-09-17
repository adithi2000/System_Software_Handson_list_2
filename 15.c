/*====================================================================================================================
 * Program: 15.c
 * Author : Adithi.P
 * Description: Write a simple program to send some data from parent to the child process.
 * Date : 11th September,2025
===============================================================================================================*/
#include<stdio.h>
#include<unistd.h>

int main(void){
	int fd[2];
	char buf[19];
	pipe(fd);

	if(!fork()){
		close(fd[0]);
		write(fd[1],"Hello from child \n",18);
	}
	else{
		close(fd[1]);
		read(fd[0],buf,18);
		printf("Value is Buff = %s \n",buf);
	}
}
/*==============================================================================================================
 * Output
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 15.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 15.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Value is Buff = Hello from child
*/
