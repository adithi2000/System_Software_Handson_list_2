/*=============================================================================================
 * Name : 20a.c
 * Author : Adithi.P
 * Descritption :  Write two programs so that both can communicate by FIFO -Use one way communication.
 * Date: 17th September,2025
 * ===========================================================================================*/
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>
#include <stdlib.h>

int main(void){
	char buf[80];
	int fd = open("myfifo",O_WRONLY);
	if(fd == -1) {
		perror("open");
		exit(0);
	}
	printf("Using fifo1 for write \n");	
		printf("Enter text for Process 1 \n");
		scanf("%[^\n]%*c",buf);
		write(fd,buf,sizeof(buf));
				
}
/*===========================================================
 * Output:
 *adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Using fifo1 for write
Enter text for Process 1
Hi this is Text */
