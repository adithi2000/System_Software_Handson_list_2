/*
 ==========================================================================================================
Program: 4.c
Author : Adithi P
Descritpion :Write a program to measure how much time is taken to execute 100 getppid ( ) 
system call. Use time stamp counter. 
Date : 20th September,2025
===========================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/time.h>

unsigned long long int rdtsc(){
	unsigned long long curr_time;
	__asm__ __volatile__("rdtsc":"=A"(curr_time));
	return curr_time;
}
int main(void){
        long long int start,end;
        printf("Calling getppid() 100 times \n");
	start = rdtsc();
         for (int i = 0; i < 100; i++) {
        getppid();
    }
	end=rdtsc();
	printf("time taken is %llu nanoseconds \n",end-start);
       
}

/* =================================================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Calling getppid() 100 times
time taken is 588317 nanoseconds
  */

                                      
