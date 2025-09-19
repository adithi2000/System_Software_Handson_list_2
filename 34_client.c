/*===========================================================================================
 * Name: 34.c
 * Author : Adithi.P
 * Description :  Write a program to create a concurrent server.
                   Client Part of the Programs
 * Date : 14th September,2025
 * ========================================================================================*/
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
        sd = socket(AF_INET,SOCK_STREAM,0);
        serv.sin_family=AF_INET;
        serv.sin_addr.s_addr=INADDR_ANY;
        serv.sin_port=htons(8080);
        connect(sd,(void *)(&serv),sizeof(serv));
        write(sd,"Hello Server \n",14);
        read(sd,buf,sizeof(buf));
        printf("Msg from server : %s \n",buf);
}
