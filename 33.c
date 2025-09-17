#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main()
{
	printf("The server program started \n");
	struct sockaddr_in serv,cli;
	int sd,sz,nsd;
	char buf[80];
	sd = socket(AF_UNIX,SOCK_STREAM,0);
	serv.sin_family=AF_UNIX;
	serv.sin_addr.s_addr=INADDR_ANY;
	serv.sin_port=htons(8080);
	bind(sd,(void *)(&serv),sizeof(serv));
	listen(sd,5);
	sz=sizeof(cli);
	nsd=accept(sd,(void *)(&cli),&sz);
	read(nsd,buf,sizeof(buf));
	printf("Msg from client : %s \n",buf);
	write(nsd,"ACK from the Server \n",21);
}
/*Output : *
 * adithi@DESKTOP-B2HISG8:~/handson_2$ cc 33.c -o server.out
adithi@DESKTOP-B2HISG8:~/handson_2$ ./server.out
The server program started
Msg from client : Hello Server */
