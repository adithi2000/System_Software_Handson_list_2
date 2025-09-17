/*===========================================================================================
 * Name: 28.c
 * Author : Adithi P
 * Description : Write a program to change the exiting message queue permission. (use msqid_ds structure)
 * Date : 17th September,2025
 * ========================================================================================*/
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
int retval = msgctl(msgid,IPC_STAT,&buf);
if(retval == -1){
        printf("error in msgq metadata retention \n");
}
printf("Present Access permissions: %o\n", buf.msg_perm.mode);
buf.msg_perm.mode=0644;
msgctl(msgid, IPC_SET, &buf);
}
/*==================================================================================
 * Output 
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 28.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 28.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6130d911 3          adithi     744        3            1

adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Present Access permissions: 744
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6130d911 3          adithi     644        3            1*/
