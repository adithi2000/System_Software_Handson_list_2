#include<stdio.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<fcntl.h>
#include<stdio.h>
#include<unistd.h>

int main(){
         printf("The client  program started \n");
	struct sockaddr_in serv;
        int sd;
        char buf[80];
        sd = socket(AF_UNIX,SOCK_STREAM,0);
        serv.sin_family=AF_UNIX;
        serv.sin_addr.s_addr=INADDR_ANY;
        serv.sin_port=htons(8080);
        connect(sd,(void *)(&serv),sizeof(serv));
	write(sd,"Hello Server \n",14);
        read(sd,buf,sizeof(buf));
        printf("Msg from server : %s \n",buf);
}
/*output :
 * adithi@DESKTOP-B2HISG8:~/handson_2$ cc 33_client.c -o client.out
adithi@DESKTOP-B2HISG8:~/handson_2$ ./client.out
The client  program started
Msg from server : ACK from the Server */
