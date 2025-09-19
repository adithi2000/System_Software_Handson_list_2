/*=================================================================================================================
 * Name:32c.c
 * Author : Adithi P
 * Description :Write a program to implement semaphore to protect any critical section.
                        c. protect multiple pseudo resources ( may be two) using counting semaphore
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
	//Counting semaphore 0x6230d911 1 being used, uses counting semaphore value of 5, created in 31b.c
        semkey=ftok(".",'b');
        semid=semget(semkey,1,0);
        struct sembuf op = {0,-1,0};

        //Critical Section
        semop(semid,&op,1);
        printf("Data read : \n");
        printf("Data : %s \n",data);
        printf("press Enter before exiting CS \n");
        getchar();
        op.sem_op=1;
        semop(semid,&op,1);
}
/*======================================================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ vi 32c.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status

adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems

adithi@DESKTOP-B2HISG8:~/handson_2$ cc 31b.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems
0x6230d911 0          adithi     666        1
adithi@DESKTOP-B2HISG8:~/handson_2$ echo "executing 32b_shm.c for creating shared memory segment"
executing 32b_shm.c for creating shared memory segment
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 32_shm_creat.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status
0x6230d911 0          adithi     744        1024       0

adithi@DESKTOP-B2HISG8:~/handson_2$ echo "Write Data to shm via 32b_write"
Write Data to shm via 32b_write
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 32b_write.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Enter the Text
Data write :
Hi
Sleeping for 5s before CS
adithi@DESKTOP-B2HISG8:~/handson_2$ vi 32c.c
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 32c.c
// 1:
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Data read :
Data : Hi
press Enter before exiting CS

//2: 
//adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Data read :
Data : Hi
press Enter before exiting CS

//3:
////adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out

*/
