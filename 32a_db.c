/*====================================================================================
 * Name: 32a_db.c
 * Author : Adithi P
 * Description :Write a program to implement semaphore to protect any critical section. 
a. rewrite the ticket number creation program using semaphore 
 * Date : 18th September,2025
 * OUTPUT in 32a_output.txt
 * ====================================================================================*/
//db creation
//
#include<stdio.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<unistd.h>
#include<stdlib.h>

int main(void){
	int i,fd;
	struct{
		int train_num;
		int ticket_count;
	}db[3];
	for(i=0;i<3;i++){
		db[i].train_num=i+1;
		db[i].ticket_count=0;
	}
	fd=open("record.txt",O_RDWR|O_CREAT,0744);
	write(fd,db,sizeof(db));
	close(fd);
}
 
