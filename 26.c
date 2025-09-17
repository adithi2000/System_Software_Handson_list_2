/*======================================================================================
 * Name: 26.c
 * Author : Adithi.P
 * Description : Write a program to send messages to the message queue. Check $ipcs -q
 * Date: 17th September,2025
 * =====================================================================================*/
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>

int main(void){
int msgid,size;
key_t key;
struct msg {
	long int mtype;
	char message[80];
}myq;

key=ftok(".",'a');
msgid=msgget(key,0);
 printf("Enter message type: ");
 scanf("%ld", &myq.mtype);
 printf("Enter message text:");
 scanf("%s", myq.message);
 size = strlen(myq.message);
 msgsnd(msgid,&myq,size+1,0);
 }

/*===============================================================================
 * Output: 
 * adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6130d911 3          adithi     744        0            0

adithi@DESKTOP-B2HISG8:~/handson_2$ cc 26.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Enter message type: 1
Enter message text:Hi
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6130d911 3          adithi     744        3            1*/
