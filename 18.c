/*=======================================================================================================
 * Name: 18.c
 * Author : Adithi P
 * Description : Write a program to find out total number of directories on the pwd.
execute ls -l | grep ^d | wc ? Use only dup2.
 * Date: 11th September,2025
 * =======================================================================================================*/
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main(void){
        int fd1[2];
	int fd2[2];
        pipe(fd1);
	pipe(fd2);
        if(!fork()){
                close(1);
                dup2(fd1[1],1);
                close(fd1[0]);
		close(fd2[0]);
		close(fd2[1]);
                execlp("ls","ls","-l",NULL);
        }
        else{
		if(!fork()){
			close(0);
			dup2(fd1[0],0);
			close(1);
			dup2(fd2[1],1);
			close(fd2[0]);
			close(fd1[1]);
			execlp("grep","grep","^d",NULL);
		}
		else{
			close(0);
			close(fd1[1]);
			close(fd1[1]);
			close(fd2[1]);
			dup2(fd2[0],0);
			execlp("wc","wc",NULL);
		}
		
        }
}
/*==========================================================================================
 * Output
 * adithi@DESKTOP-B2HISG8:~/handson_2$ cc 18.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
      0       0       0  */

