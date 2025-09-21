/*==================================================================
 * Name : 10a.c
 * Author : Adithi P
 * Description: Write a separate program using sigaction system call to catch the following signals. 
   a. SIGSEGV  
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
	sigaction(SIGSEGV, &sa, NULL);
	int n;
	printf("Enter a value \n");
	scanf("%d",n);
}
void handler(int signum){
        printf("signal caught %d \n",signum);
        exit(0);
}
/*====================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 10a.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 10a.c
8a.c: In function ‘main’:
8a.c:21:17: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘int’ [-Wformat=]
   21 |         scanf("%d",n);
      |                ~^  ~
      |                 |  |
      |                 |  int
      |                 int *
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Enter a value
1
signal caught 11 : Segmentation fault */

