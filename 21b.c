/*=============================================================================================
 * Name : 20b.c
 * Author : Adithi.P
 * Descritption :  Write two programs so that both can communicate by FIFO -Use two way communication.
 * Date: 17th September,2025
 * ======================================================================================= */
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
int main(void){                                                                                                                              char buf[80];
        char buf1[80];                                                                                                                       int fd = open("myfifo",O_RDONLY);
	int fd1 = open("myfifo1",O_WRONLY);
        for(;;){
                printf("Enter text for Process 2 \n");
                scanf("%[^\n]%*c",buf);
                write(fd1,buf,sizeof(buf));

                read(fd,buf1,sizeof(buf1));
                printf("from myfifo %s \n",buf1);
        }
}
/*==============================================================
 * OutPut : 
 * tadithi@DESKTOP-B2HISG8:~/handson_2$ cc 21b.c -o 21b
adithi@DESKTOP-B2HISG8:~/handson_2$ ./21b
Enter text for Process 2
Hi
from myfifo Hi
Enter text for Process 2
Hello 2
from myfifo Hello
Enter text for Process 2
^Z
[2]+  Stopped                 ./21b*/
