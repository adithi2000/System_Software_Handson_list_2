/*==================================================================
 * Name : 10c.c
 * Author : Adithi P
 * Description:  Write a separate program using sigaction system call to catch the following signals. 
    		c. SIGFPE 
 * Date: 20th September,2025
 * ====================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>

void handler(int signum);
 
int main(void){
	struct sigaction sa;
        sa.sa_handler=handler;
        sigemptyset(&sa.sa_mask);
        sa.sa_flags=0;
        sigaction(SIGFPE, &sa, NULL);
	printf("Catching SIGFPE \n");
	int a = 5, b = 0;
    int c = a / b;

    printf("Result: %d\n", c);
}
void handler(int signum){
        printf("signal caught %d \n",signum);
        exit(0);
}
/*====================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ cc 10c.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Catching SIGFPE
signal caught 8 */

