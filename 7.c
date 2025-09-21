/*===================================================================================
 * Name: 7.c
 * Author : Adithi.P
 * Description:  Write a simple program to print the created thread ids.
 * Date : 20th September,2025
 * ==================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

void thread_handler(void){
	printf("The thread id is %lu\n", (unsigned long)pthread_self());
}

int main(void){
	pthread_t thread;
	pthread_create(&thread,NULL,(void *)thread_handler,NULL);
	 pthread_create(&thread,NULL,(void *)thread_handler,NULL);
	  pthread_create(&thread,NULL,(void *)thread_handler,NULL);
	pthread_join(thread,NULL);
}

/*==============================================================================
 * Output:
  adithi@DESKTOP-B2HISG8:~/handson_2$ cc 7.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
The thread id is 127526835844800
The thread id is 127526827452096
The thread id is 127526819059392 
*/

/*INFO :if you need to pass more than one value (or a mix of types) to a thread, the cleanest and safest way is to bundle them into a struct, pass a pointer to that struct as the void *arg in pthread_create(), and then cast it back inside the thread function. */
