/*==============================================================================
 * Name:24.c
 * Author : Adithi P
 * Description :  Write a program to create a message queue and print the key and message queue id. 
 * date : 17th September,2025
 * =============================================================================*/
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
msgid=msgget(key, IPC_CREAT|IPC_EXCL|0744);
 printf("key=0x%0x\t msgid=%d\n", key, msgid);
 }
/*=====================================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ cc 24.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
key=0x6130d911   msgid=-1
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6130d911 2          adithi     744        0            0

adithi@DESKTOP-B2HISG8:~/handson_2$ ipcrm -q 2
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages

adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
key=0x6130d911   msgid=3

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6130d911 3          adithi     744        0            0*/
