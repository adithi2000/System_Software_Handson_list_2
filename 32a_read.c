/*
 ==========================================================================================================
Program: 32a_read.c
Author : Adithi P
Descritpion : Write a program to implement semaphore to protect any critical section. 
a. rewrite the ticket number creation program using semaphore
Date : 18th September,2025
FOR OUTPUT REFER TO 32a_Output.txt
===========================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/stat.h>

union semun {
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
};

int main(void){
        int fd,input;
        struct {
                int train_num;
                int ticket_count;
        }db;
	union semun sem1;
	int key,semid;
	key=ftok(".",'a');
	semid=semget(key,1,0);
	struct sembuf op={0,-1,0};

        fd=open("record.txt",O_RDWR);

        printf("Select train number : \n");
        scanf("%d",&input);

        // Read:
	
        printf("before entering CS \n");
	 printf("Read Lock will be implemented \n");
	lseek(fd,(input-1)*sizeof(db),SEEK_SET);
	semop(semid,&op,1);
        read(fd,&db,sizeof(db));
        printf("In CS\n");
        printf("Train number entered %d \n",db.train_num);
        printf("ticket count %d \n" , db.ticket_count);
	sleep(10);
        printf("Finish Read \n");
        getchar();
	op.sem_op=1;
	semop(semid,&op,1);
	close(fd);
}
