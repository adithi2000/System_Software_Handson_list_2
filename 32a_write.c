/*
 ==========================================================================================================
Program: 32a_write.c
Author : Adithi P
Descritpion : Write a program to implement semaphore to protect any critical section. 
a. rewrite the ticket number creation program using semaphore
Date : 18th September,2025
FOR OUTPUT REFER TO 32a_Output.txt
===========================================================================================================
*/
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/sem.h>
#include<sys/ipc.h>

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

	fd=open("record.txt",O_RDWR);
	 union semun sem1;
        int key,semid;
        key=ftok(".",'a');
        semid=semget(key,1,0);
        struct sembuf op={0,-1,0};

	printf("Select train number : \n");
	scanf("%d",&input);
       // Write
	printf("Write Lock will be implemented \n");

        semop(semid,&op,1);
	lseek(fd,(input-1)*sizeof(db),SEEK_SET);
	read(fd,&db,sizeof(db));
	printf("before entering CS \n");
	printf("In CS\n");
	printf("Train number entered %d \n",db.train_num);
	printf("Initial ticket count %d \n" , db.ticket_count);
	db.ticket_count++;
	printf("New ticket count will be %d \n",db.ticket_count);
	lseek(fd,-1*sizeof(db),SEEK_CUR);
	sleep(10);
	write(fd,&db,sizeof(db));
	printf("To book the ticket press Enter \n");
	getchar();

	op.sem_op=1;
        semop(semid,&op,1);
	close(fd);
}
