/*=============================================================================================
 * Name : 20b.c
 * Author : Adithi.P
 * Descritption :  Write two programs so that both can communicate by FIFO -Use one way communication.
 * Date: 17th September,2025
 * ===========================================================================================*/
#include<unistd.h>
#include<stdio.h>
#include<fcntl.h>

int main(void){
        char buf[80];
        int fd = open("myfifo",O_RDONLY);
	if(fd == -1){
		perror("opening file not possible \n");
	}

	printf("Will be using fifo1 for read \n");
   
               int n = read(fd,buf,sizeof(buf));
	       if ( n < 0){
		       perror("Read issue \n");
	       }
		printf("Text recieved from process 1 : %s",buf);
      
}

/*===============================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ ./20b
Will be using fifo1 for read
Text recieved from process 1 : Hi this is Text */
