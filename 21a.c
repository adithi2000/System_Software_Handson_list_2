/*=============================================================================================
 * Name : 21a.c
 * Author : Adithi.P
 * Descritption :  Write two programs so that both can communicate by FIFO -Use two way communication.
 * Date: 17th September,2025
 * ===========================================================================================*/
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(void){
        char buf[80];
	char buf1[80];
        int fd = open("myfifo",O_WRONLY);
	int fd1 = open("myfifo1",O_RDONLY);
        printf("Using fifo1 for write \n");
        for(;;){
                printf("Enter text for Process 1 \n");
                scanf("%[^\n]%*c",buf);
                write(fd,buf,sizeof(buf));
		
		read(fd,buf1,sizeof(buf1));
		printf("from myfifo1 %s \n",buf1);
        }
}

/*==============================================================Output 
 * adithi@DESKTOP-B2HISG8:~/handson_2$ mkfifo myfifo1
adithi@DESKTOP-B2HISG8:~/handson_2$ ls -l | grep ^p
prwxrwxrwx 1 adithi adithi     0 Sep 17 17:41 myfifo
prw-r--r-- 1 adithi adithi     0 Sep 17 17:44 myfifo1
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 21a.c -o 21a
adithi@DESKTOP-B2HISG8:~/handson_2$ ./21a
Using fifo1 for write
Enter text for Process 1
Hi
from myfifo1
Enter text for Process 1
Hello
from myfifo1
Enter text for Process 1
^Z
[1]+  Stopped                 ./21a*/
