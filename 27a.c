/*======================================================================================
 * Name: 27a.c
 * Author : Adithi.P
 * Description : 27. Write a program to receive messages from the message queue. 
			a. with 0 as a flag 
 * Date: 17th September,2025
 * =====================================================================================*/

#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(void){
int msgid,size; 
	struct msg {                                                                                                                           struct msg {
        long int mtype;
        char message[80];
}myq;                                                                                                                                                                                                                                                                     key=ftok(".",'a');                                                                                                                   msgid=msgget(key,0);
printf("Enter message type: ");
scanf("%ld", &myq.mtype);
int ret = msgrcv(msgid, &myq, sizeof(myq.message), myq.mtype,
	0);
printf("Message recieved of type %ld : %s \n",myq.mtype,myq.message);
}

/*=======================================================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 27a.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 27a.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Enter message type: 1
Message recieved of type 1 : Hi */

