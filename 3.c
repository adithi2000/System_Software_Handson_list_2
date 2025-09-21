/*=================================================================================
 * Name: 3.c
 * Author : Adithi P
 * Description :  Write a program to set (any one) system resource limit. Use setrlimit system call.
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
printf("R_LIMIT of No of Files \n");
getrlimit(RLIMIT_NOFILE,&lim);
printf("Soft limit: %ld\n", (long)lim.rlim_cur);
        printf("Hard limit: %ld\n", (long)lim.rlim_max);

lim.rlim_cur=1050;
lim.rlim_max=10480;
setrlimit(RLIMIT_NOFILE,&lim);
printf("After setting limit \n");
getrlimit(RLIMIT_NOFILE,&lim);
printf("Soft limit: %ld\n", (long)lim.rlim_cur);
        printf("Hard limit: %ld\n", (long)lim.rlim_max);
}
/*=====================================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ cc 3.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
R_LIMIT of No of Files
Soft limit: 10240
Hard limit: 1048576
After setting limit
Soft limit: 1050
Hard limit: 10480
*/
