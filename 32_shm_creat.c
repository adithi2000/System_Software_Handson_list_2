/*==========================================================================
 * Name: 32_shm_creat.c
 * Author:Adithi P
 * Description : SHM creation for 32b_read.c and 32b_write.c 
 * Date : 18th September,2025
 * ========================================================================*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/stat.h>
#include<sys/shm.h>

int main(void){
	 int key,shmid;
       
        key=ftok(".",'b');
        shmid=shmget(key,1024,IPC_CREAT|0744);
	char *data;
	data=shmat(shmid,0,0);
}



