/*=================================================================================================================
 * Name:32b_write.c                                                                                                                    * Author : Adithi P                                                                                                                  * Description :Write a program to implement semaphore to protect any critical section.
                        b. protect shared memory from concurrent write access                                                         * Date: 18th September,2025                                                                                                          * ================================================================================================================*/
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
        data=shmat(shmid,0,0);
	union semun arg;
	int semkey,semid;
	semkey=ftok(".",'a');
	semid=semget(semkey,1,0);
	struct sembuf op = {0,-1,0};
        printf("Enter the Text \n");
	//Critical Section
	semop(semid,&op,1);
	printf("Data write : \n");
        scanf("%[^\n]",data);
	printf("Sleeping for 5s before CS \n");
	sleep(5);
	op.sem_op=1;
	semop(semid,&op,1);

}
/*====================================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ ./32b_write
Enter the Text
Data write :
adithi
Sleeping for 5s before CS
adithi@DESKTOP-B2HISG8:~/handson_2$ ./32b_read
Data read :
Data : adithi
Sleeping 5s before releasing CS */
