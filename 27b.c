/*======================================================================================
 * Name: 27a.c
 * Author : Adithi.P
 * Description : 27. Write a program to receive messages from the message queue.
                       b. with IPC_NOWAIT as a flag
 * Date: 17th September,2025
 * =====================================================================================*/

#include <sys/msg.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>

int main(void){
int msgid,size;                                                                                                                      key_t key;                                                                                                                           struct msg {
        long int mtype;
        char message[80];
}myq;                                                                                                                                                                                                                                                                     key=ftok(".",'a');                                                                                                                   msgid=msgget(key,0);
printf("Enter message type: ");
scanf("%ld", &myq.mtype);
int ret = msgrcv(msgid, &myq, sizeof(myq.message), myq.mtype,
        IPC_NOWAIT);
printf("Message recieved of type %ld : %s \n",myq.mtype,myq.message);

}
/*============================================================================
 * Output :
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 27b.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 26.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Enter message type: 2
Enter message text:Hi
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 27b.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Enter message type: 1
Message recieved of type 1 :
adithi@DESKTOP-B2HISG8:~/handson_2$ echo "Exited since no message of id 1 exists
> "
Exited since no message of id 1 exists */
