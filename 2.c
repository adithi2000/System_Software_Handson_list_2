/*=================================================================================
 * Name: 2.c
 * Author : Adithi P
 * Description : 2. Write a program to print the system resource limits. Use getrlimit system call.
 * Date: 20th September,2025
 * =====================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include <signal.h>
#include <sys/time.h>
#include<stdlib.h>
#include<sys/resource.h>

int main(void){
struct rlimit lim;

getrlimit(RLIMIT_NOFILE,&lim);
printf("Soft limit: %ld\n", (long)lim.rlim_cur);
        printf("Hard limit: %ld\n", (long)lim.rlim_max);

getrlimit(RLIMIT_AS,&lim);
printf("Soft limit: %ld\n", (long)lim.rlim_cur);
        printf("Hard limit: %ld\n", (long)lim.rlim_max);

getrlimit(RLIMIT_STACK,&lim);                                                                                                           printf("Soft limit: %ld\n", (long)lim.rlim_cur);
        printf("Hard limit: %ld\n", (long)lim.rlim_max);
getrlimit(RLIMIT_CPU,&lim);                                                                                                           printf("Soft limit: %ld\n", (long)lim.rlim_cur);
        printf("Hard limit: %ld\n", (long)lim.rlim_max);
}
/*=====================================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ cc 2.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Soft limit: 10240
Hard limit: 1048576
Soft limit: -1
Hard limit: -1
Soft limit: 8388608
Hard limit: -1
Soft limit: -1
Hard limit: -1
*/
