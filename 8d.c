/*==================================================================
 * Name : 8d.c
 * Author : Adithi P
 * Description: 8. Write a separate program using signal system call to catch the following signals. 
    		  d. SIGALRM (use alarm system call) 
 * Date: 20th September,2025
 * ====================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>

void handler(int signum);
 
int main(void){
	signal(SIGALRM,handler);
	alarm(3);
	while(1);

}
void handler(int signum){
        printf("signal caught %d \n",signum);
        exit(0);
}
/*====================================
 * Output:
 adithi@DESKTOP-B2HISG8:~/handson_2$ cc 8d.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
signal caught 14
*/

