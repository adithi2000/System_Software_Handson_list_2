/*=================================================================================================================
 * Name: 17b.c
 * Author : Adithi P
 * Description :  Write a program to execute ls -l | wc.
                        a. use dup
                        b. use dup2
                        c. use fcntl
* Date: 11th September,2025
* ==================================================================================================================
*/
#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main(void){
        int fd[2];
        pipe(fd);
        if(!fork()){
                close(1);
                fcntl(fd[1],F_DUPFD,1);
                close(fd[0]);
                execlp("ls","ls","-l",NULL);
        }
        else{
                close(0);
                close(fd[1]);
                fcntl(fd[0],F_DUPFD,0);
		 execlp("wc","wc",NULL);
        }
}
/* ===================================================================================\
 * Output
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 17c.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 17c.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
     15     126     745*/
