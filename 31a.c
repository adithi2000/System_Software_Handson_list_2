/*=================================================================================================
 * Name: 31a.c
 * Author : Adithi P
 * Description : Write a program to create a semaphore and initialize value to the semaphore. 
		a. create a binary semaphore
  * Date: 18th September,2025
  * ===============================================================================================*/
#include<stdio.h>
#include<unistd.h>
#include<sys/sem.h>

union semun {
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
};

int main(void){
	union semun arg;
	int key,semid;
	key =ftok(".",'a');
	semid = semget(key,1,IPC_CREAT|0666);
	arg.val=1;
	semctl(semid,0,SETVAL,arg);
}

/*============================================================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 31a.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 31a.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems

adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems
0x6130d911 0          adithi     666        1 */

