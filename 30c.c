 /*=================================================================================
  * Name: 30c.c
  * Author : Adithi P
  * Description: 30. Write a program to create a shared memory.
		c. detach the shared memory	
  * Date: 16th September,2025
  * ==============================================================================*/
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>

int main(void){
        int key,shmid;
        key=ftok(".",'b');
        char *data;
        shmid=shmget(key,1024,0);
	data=shmat(shmid,0,0);
	shmdt(data);
}

