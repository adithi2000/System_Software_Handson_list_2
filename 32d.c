/*
 ==========================================================================================================
Program: 32d.c
Author : Adithi P
Descritpion : Write a program to implement semaphore to protect any critical section.
		d. remove the created semaphore
Date : 18th September,2025
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

int main(void){
        int key,semid;
        key=ftok(".",'b');
        semid=semget(key,1,0);
	semctl(semid, 0, IPC_RMID);
}

/*=====================================================================
 * Output 
 * adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems
0x6230d911 0          adithi     666        1

adithi@DESKTOP-B2HISG8:~/handson_2$ cc 32d.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems*/
