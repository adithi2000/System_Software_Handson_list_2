/*==============================================================
 * Name:22.c
 * Author : Adithi P
 * Description :  Write a program to wait for data to be written into FIFO within 10 seconds, use select 
system call with FIFO. 
* Date: 17th September,2025
* ==============================================================*/
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>

int main(void){
        fd_set wr_fds;
	char buf[80];
	struct timeval tv;
	FD_ZERO(&wr_fds);
        int fd = open("myfifo",O_RDONLY);
	FD_SET(fd,&wr_fds);
	tv.tv_sec=10;
	tv.tv_usec=0;
	int retval = select(fd+1,&wr_fds,NULL,NULL,&tv);
      if (retval ==-1){
 perror("Error occurred");}
 else if (retval){
 printf("Data is available for reading within 10 seconds \n");
 read(fd,buf,sizeof(buf));
 printf("Data written is %s \n",buf);
 }

 else{
 printf("Data is not available for reading within 10 seconds");}
 }
/*==============================================================
 * Output
 * adithi@DESKTOP-B2HISG8:~/handson_2$ cc 21a.c -o 21a
adithi@DESKTOP-B2HISG8:~/handson_2$ ./21a
Using fifo1 for write
Enter text for Process 1
Hi

adithi@DESKTOP-B2HISG8:~/handson_2$ vi 22.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 22.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Data is available for reading within 10 seconds
Data written is Hi
*/

