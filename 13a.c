/*==================================================================================
 * Name: 13a.c
 * Author : Adithi P
 * Description:  Write two programs: first program is waiting to catch SIGSTOP signal, the second program 
		will send the signal (using kill system call). Find out whether the first program is able to catch 
		the signal or not
  * Date: 20th September,2025
  * ===============================================================================*/
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<signal.h>

//reciever program
void handler(int signum);

int main(void){
	printf("My pid is %d \n",getpid());
        signal(SIGSTOP,handler);
	sleep(10);
	printf("SIGSTOP not caught \n");
}
void handler(int signum){
        printf("signal caught %d \n",signum);
        exit(0);
}

/*=========================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 13a.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 13a.c -o 13a
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 13b.c -o 13b
adithi@DESKTOP-B2HISG8:~/handson_2$ ./13a
My pid is 1217

[2]+  Stopped                 ./13a
adithi@DESKTOP-B2HISG8:~/handson_2$ ./13b 1217 */
