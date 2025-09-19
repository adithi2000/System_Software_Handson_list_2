/*=================================================================================================
 * Name: 31b.c
 * Author : Adithi P
 * Description : Write a program to create a semaphore and initialize value to the semaphore.
                b. create a counting semaphore
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
        key =ftok(".",'b');
        semid = semget(key,1,IPC_CREAT|0666);
        arg.val=22;
        semctl(semid,0,SETVAL,arg);
}
/*==============================================================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems
0x6130d911 0          adithi     666        1

adithi@DESKTOP-B2HISG8:~/handson_2$ cc 31b.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -s

------ Semaphore Arrays --------
key        semid      owner      perms      nsems
0x6130d911 0          adithi     666        1
0x6230d911 1          adithi     666        1     */
