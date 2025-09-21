/*===================================================================================
 * Name: 6.c
 * Author : Adithi.P
 * Description: 6. Write a simple program to create three threads.
 * Date : 20th September,2025
 * ==================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void thread_handler(void *value){
	printf("Inside thread %d \n",*(int*)value);
}

int main(void){
	pthread_t thread;
	int value = 0;
	pthread_create(&thread,NULL,(void *)thread_handler,&value);
	value ++;
	pthread_create(&thread,NULL,(void *)thread_handler,&value);
        value++;
	pthread_create(&thread,NULL,(void *)thread_handler,&value);
	value++;
	pthread_join(thread,NULL);
}

/*==============================================================================
 * Output:
  adithi@DESKTOP-B2HISG8:~/handson_2$ cc 6.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Inside thread 1
Inside thread 2
Inside thread 3
*/
