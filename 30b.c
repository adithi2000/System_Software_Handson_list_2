/*======================================================================================
 * Name:30b.c
 * Author:Adithi.P
 * Description : 30. Write a program to create a shared memory.
		b. attach with O_RDONLY and check whether you are able to overwrite.

 * Date : 16th September,2025
 * =======================================================================================*/
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include <sys/types.h>

int main(void){
	int key,shmid;
	key=ftok(".",'b');
	char *data;
	shmid=shmget(key,1024,0);
	data=shmat(shmid,0,SHM_RDONLY);
	printf("Text from shared memory : %s \n",data);
}

