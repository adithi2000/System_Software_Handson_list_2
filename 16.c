/*===========================================================================================================
 * Name : 16.c
 * Author : Adithi.P
 * Desription: Write a program to send and receive data from parent to child vice versa. Use two way
communication.
* Date : 11th September,2025
============================================================================================================*/
#include<stdio.h>
#include<unistd.h>

int main(void){
        int fd1[2];
	int fd2[2];
        char buf1[13];
	char buf2[13];
        pipe(fd1);
	pipe(fd2);

        if(!fork()){
                close(fd1[0]);
		close(fd2[1]);
		write(fd1[1],"Hello pipe1 \n",13);
		read(fd2[0],buf2,13);
		printf("Child reading Pipe 2 written by parent : %s \n",buf2);
        }
        else{
                close(fd1[1]);
                close(fd2[0]);
                write(fd2[1],"Hello pipe2 \n",13);
                read(fd1[0],buf1,13);
                printf("Parent reading Pipe 1 written by child : %s \n",buf1);
        }
}
/*==================================================================================================================
 * Output
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 16.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 16.c -o 16.o
adithi@DESKTOP-B2HISG8:~/handson_2$ ./16.o
Child reading Pipe 2 written by parent : Hello pipe2
Parent reading Pipe 1 written by child : Hello pipe1
*/
