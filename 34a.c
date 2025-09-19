/*===========================================================================================
 * Name: 34a.c
 * Author : Adithi.P
 * Description :  Write a program to create a concurrent server. 
			a. use fork
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

int main()
{
        printf("The server program started \n");
        struct sockaddr_in serv,cli;
        int sd,sz,nsd;
        char buf[80];
        //sd = socket(AF_UNIX,SOCK_STREAM,0);
        //serv.sin_family=AF_UNIX;
	sd = socket(AF_INET,SOCK_STREAM,0);
        serv.sin_family=AF_INET;
        serv.sin_addr.s_addr=INADDR_ANY;
        serv.sin_port=htons(8080);
        bind(sd,(void *)(&serv),sizeof(serv));
        listen(sd,5);

	for(int i =1;i<6;i++){
	sz=sizeof(cli);
        nsd=accept(sd,(void *)(&cli),&sz);
	if(nsd){
		printf("client %d connected \n",nsd);
	}
	if(!fork()){
	close(sd);
	 memset(buf, 0, sizeof(buf));
        read(nsd,buf,sizeof(buf));
        printf("Msg from client : %s \n",buf);
        write(nsd,"ACK from the Server \n",21);
	exit(0);
	}
	else{
		close(nsd);
	}
	}
	close(sd);
	return 0;
}
/*================================================================
 * Output: 
 * adithi@DESKTOP-B2HISG8:~/handson_2$ cc 34a.c -o serv
adithi@DESKTOP-B2HISG8:~/handson_2$ ./serv
The server program started
client 4 connected
Msg from client : Hello Server

client 4 connected
Msg from client : Hello Server

client 4 connected
Msg from client : Hello Server

client 4 connected
Msg from client : Hello Server

^Z
[1]+  Stopped                 ./serv

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

//4:
//adithi@DESKTOP-B2HISG8:~/handson_2$ ./cli
The client  program started
Msg from server : ACK from the Server

*/
