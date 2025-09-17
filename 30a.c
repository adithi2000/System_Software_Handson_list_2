/*=================================================================================================================
 * Name:30a.c
 * Author : Adithi P
 * Description : 30. Write a program to create a shared memory.
			a. write some data to the shared memory
 * Date: 16th September,2025
 * ================================================================================================================*/
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>

int main(void){
	int key,shmid;
	char *data;
	key=ftok(".",'b');
	shmid=shmget(key,1024,IPC_CREAT|0744);
	data=shmat(shmid,0,0);
	printf("Enter the Text \n");
	scanf("%[^\n]",data);
}
