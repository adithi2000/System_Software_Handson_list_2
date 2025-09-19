/*=================================================================================================================
 * Name:32b_read.c
 * Author : Adithi P
 * Description :Write a program to implement semaphore to protect any critical section. 
			b. protect shared memory from concurrent write access  
 * Date: 18th September,2025
 * ================================================================================================================*/
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<stdlib.h>

union semun{
        int val;
        struct semid_ds *buff;
        unsigned short int *array;
};
int main(void){
        int key,shmid;
        char *data;
        key=ftok(".",'b');
        shmid=shmget(key,1024,0);
        data=shmat(shmid,0,SHM_RDONLY);
        union semun arg;
        int semkey,semid;
        semkey=ftok(".",'a');
        semid=semget(semkey,1,0);
        struct sembuf op = {0,-1,0};
       
        //Critical Section
        semop(semid,&op,1);
        printf("Data read : \n");
        printf("Data : %s \n",data);
	printf("Sleeping 5s before releasing CS \n");
	sleep(5);
        op.sem_op=1;
        semop(semid,&op,1);
}
