/*==============================================================================
 * Name: 29.c
 * Author : Adithi P
 * Description : Write a program to remove the message queue.
 * Date : 17th September,2025
 * ============================================================================*/
#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
int main(void){
int msgid,size;
key_t key;
struct msg {
        long int mtype;
        char message[80];
}myq;

key=ftok(".",'a');
msgid=msgget(key,0);
struct msqid_ds buf;
msgctl(msgid,IPC_RMID,&buf);
}
/*==========================================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 29.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 29.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6130d911 3          adithi     644        3            1

adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
*/
