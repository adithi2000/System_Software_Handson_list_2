/*======================================================================================
 * Name:30d.c
 * Author:Adithi.P
 * Description : 30. Write a program to create a shared memory.
                	d. remove the shared memory

 * Date : 16th September,2025
 * =======================================================================================*/
#include<sys/shm.h>
#include<unistd.h>
#include<stdio.h>

int main(void){
        int key,shmid;
        key=ftok(".",'b');
        char *data;
        shmid=shmget(key,1024,0);
        shmctl(shmid,IPC_RMID,NULL);
}
/*===============================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status

adithi@DESKTOP-B2HISG8:~/handson_2$ cc 30a.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Enter the Text
Hi
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status
0x6230d911 1          adithi     744        1024       0

adithi@DESKTOP-B2HISG8:~/handson_2$ cc 30b.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
Text from shared memory : Hi
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status
0x6230d911 1          adithi     744        1024       0

adithi@DESKTOP-B2HISG8:~/handson_2$ cc 30c.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status
0x6230d911 1          adithi     744        1024       0

adithi@DESKTOP-B2HISG8:~/handson_2$ cc 30d.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
adithi@DESKTOP-B2HISG8:~/handson_2$ ipcs -m

------ Shared Memory Segments --------
key        shmid      owner      perms      bytes      nattch     status
*/
