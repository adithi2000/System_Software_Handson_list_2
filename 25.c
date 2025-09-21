/*========================================================================
 * Name: 25.c
 * Author : Adithi P
 * Description :
 * Write a program to print a message queue's  (use msqid_ds and ipc_perm structures) 
	a. access permission 
	b. uid, gid 
	c. time of last message sent and received    
	d. time of last change in the message queue 
	d. size of the queue 
	f. number of messages in the queue  
	g. maximum number of bytes allowed  
	h. pid of the msgsnd and msgrcv
 *Date : 17th September,2025
*===========================================================================*/
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
printf("a. Access permissions: %o\n", buf.msg_perm.mode);
    printf("b. UID: %d, GID: %d\n", buf.msg_perm.uid, buf.msg_perm.gid);
    printf("c. Time of last msg sent: %s", buf.msg_stime ? ctime(&buf.msg_stime) : "Not yet sent\n");
    printf("   Time of last msg received: %s", buf.msg_rtime ? ctime(&buf.msg_rtime) : "Not yet received\n");
    printf("d. Time of last change: %s", buf.msg_ctime ? ctime(&buf.msg_ctime) : "Not changed\n");
    printf("e. Size of the queue (current bytes): %lu\n", buf.__msg_cbytes); 
    printf("f. Number of messages in the queue: %lu\n", buf.msg_qnum);
    printf("g. Max number of bytes allowed: %lu\n", buf.msg_qbytes);
    printf("h. PID of last msgsnd: %d\n", buf.msg_lspid);
    printf("   PID of last msgrcv: %d\n", buf.msg_lrpid);
 
    }
/*=======================================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ cc 25.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
a. Access permissions: 744
b. UID: 1000, GID: 1000
c. Time of last msg sent: Wed Sep 17 11:21:03 2025
   Time of last msg received: Wed Sep 17 11:17:52 2025
d. Time of last change: Wed Sep 17 11:14:05 2025
e. Size of the queue (current bytes): 3
f. Number of messages in the queue: 1
g. Max number of bytes allowed: 16384
h. PID of last msgsnd: 1743
   PID of last msgrcv: 1706
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -q

------ Message Queues --------
key        msqid      owner      perms      used-bytes   messages
0x6130d911 3          adithi     744        3            1        */
