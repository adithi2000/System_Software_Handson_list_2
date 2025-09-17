/*===================================================================================================================
Name: 14.c
Author: Adithi.P
Description: Write a simple program to create a pipe, write to the pipe, read from pipe and display on
the monitor. 
Date: 11th September,2025
====================================================================================================================*/
#include<stdio.h>
#include<unistd.h>

int main(void){
	int fd[2];
	char buff[10];
	pipe(fd);
	getchar();
	write(fd[1],"Hello \n",8);
	read(fd[0],buff,7);
	printf("Buffer Value is %s \n",buff);

}

/*=======================================================================================================================
 * Output :
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 14.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 14.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out

Buffer Value is Hello
 */
