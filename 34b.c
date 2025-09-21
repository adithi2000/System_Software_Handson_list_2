/*===========================================================================================
 * Name: 34a.c
 * Author : Adithi.P
 * Description :  Write a program to create a concurrent server. 
			b. use pthread_create
 * Date : 14th September,2025
 * ========================================================================================*/
#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>
#include <arpa/inet.h>


void* server_handler(void* arg) {
    int nsd = *(int *)arg;
    free(arg);
    printf("Inside thread handler \n");
 	 char buf[80];
         memset(buf, 0, sizeof(buf));
        read(nsd,buf,sizeof(buf));
        printf("Msg from client : %s \n",buf);
        write(nsd,"ACK from the Server \n",21);
	sleep(5);
	close(nsd);
        return NULL;
	//exit(0) is terminating the whole process not like fork()
	}
int main(void)
{
        printf("The server program started \n");
        struct sockaddr_in serv,cli;
        int sd,sz,nsd;
        //sd = socket(AF_UNIX,SOCK_STREAM,0);
        //serv.sin_family=AF_UNIX;
	sd = socket(AF_INET,SOCK_STREAM,0);
        serv.sin_family=AF_INET;
        serv.sin_addr.s_addr=INADDR_ANY;
        serv.sin_port=htons(8084);
        bind(sd,(void *)(&serv),sizeof(serv));
        listen(sd,5);

        sz=sizeof(cli);
	while(1){
	if((nsd=accept(sd,(void *)(&cli),&sz))>0){
		 printf("client %d connected \n",nsd);
	}
	int *cli_sd = malloc(sizeof(int));
	*cli_sd=nsd;
	pthread_t tid;
       if(pthread_create(&tid, NULL,server_handler,cli_sd)){
	       printf("thread created to handle client \n");
       }
	pthread_detach(tid);
	}
	close(sd);
}
/*================================================================
 * Output: 
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 34b.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 34b.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
The server program started
client 4 connected
Inside thread handler
Msg from client : Hello Server

client 5 connected
Inside thread handler
Msg from client : Hello Server

client 4 connected
Inside thread handler
Msg from client : Hello Server

^Z
[4]+  Stopped                 ./a.out

//Client:
//1:
//adithi@DESKTOP-B2HISG8:~/handson_2$ ./cli
The client  program started
Msg from server : ACK from the Server

//2:
//adithi@DESKTOP-B2HISG8:~/handson_2$ ./cli
The client  program started
Msg from server : ACK from the Server

//3:
//adithi@DESKTOP-B2HISG8:~/handson_2$ ./cli
The client  program started
Msg from server : ACK from the Server

*/
