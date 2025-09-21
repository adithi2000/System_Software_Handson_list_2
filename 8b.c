/*==================================================================
 * Name : 8a.c
 * Author : Adithi P
 * Description: 8. Write a separate program using signal system call to catch the following signals. 
    b. SIGINT 
 * Date: 20th September,2025
 * ====================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>

void handler(int signum);
 
int main(void){
	signal(SIGINT,handler);
	printf("Catching SIGINT \n");
	sleep(3);
}
void handler(int signum){
        printf("signal caught %d \n",signum);
        exit(0);
}
/*====================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 8b.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 8b.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Catching SIGINT
^Csignal caught 2 */

