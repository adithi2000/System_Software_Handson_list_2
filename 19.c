/* ============================================================================================================
 * Name: 19.c
 * Author: Adithi.P
 * Description: Create a FIFO file by 
		a. mknod command 
		b. mkfifo command 
		c. use strace command to find out, which command (mknod or mkfifo) is better. 
		c. mknod system call 
		d. mkfifo library function

* Date: 17th September,2025
* ====================================================================================================*/
#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<string.h>

int main(void){
	// fifo1: made using mknod and mkfifo system call
	char *f1 = "Fifo1_mknod";
	char *f2 = "Fifo2_mkfifo";
	//int mknod(const char *pathname, mode_t mode, dev_t dev);
	int mknod_stat=mknod(f1,S_IFIFO|0666,0);
	int mkfifo_status=mkfifo(f2,0666);
	if(mknod_stat == -1){
		printf("error in fifo creation via mknod \n");
	}
	if(mkfifo_status == -1){
		printf("error in fifo creation via mkfifo \n");
	}
	else{
		printf("fifos created sucessfully \n");
	}
}
/*================================================================================================
 * Output
 * adithi@DESKTOP-B2HISG8:~/handson_2$ strace -c mkfifo myfifo
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 27.21    0.008218         273        30           mmap
 24.32    0.007345         216        34        13 openat
 14.96    0.004518         215        21           fstat
 13.13    0.003965         172        23           close
  8.45    0.002554         255        10           read
  4.28    0.001293         258         5           mprotect
  1.84    0.000556         185         3           brk
  1.39    0.000419         419         1           mknodat
  1.18    0.000355         177         2           pread64
  0.66    0.000199         199         1           set_tid_address
  0.65    0.000197         197         1           set_robust_list
  0.65    0.000196         196         1           arch_prctl
  0.65    0.000196         196         1           futex
  0.65    0.000196         196         1           rseq
  0.00    0.000000           0         1           munmap
  0.00    0.000000           0         2         2 access
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         2         1 statfs
  0.00    0.000000           0         1           prlimit64
  0.00    0.000000           0         1           getrandom
------ ----------- ----------- --------- --------- ----------------
100.00    0.030207         212       142        16 total
adithi@DESKTOP-B2HISG8:~/handson_2$ strace -c mknod myfifo1 p
% time     seconds  usecs/call     calls    errors syscall
------ ----------- ----------- --------- --------- ----------------
 26.06    0.011465         545        21           fstat
 22.22    0.009775         287        34        13 openat
 18.71    0.008232        1646         5           mprotect
 16.09    0.007078         235        30           mmap
  6.58    0.002894         125        23           close
  4.36    0.001916         191        10           read
  1.12    0.000494         247         2         2 access
  0.93    0.000409         204         2           pread64
  0.91    0.000400         200         2         1 statfs
  0.47    0.000207         207         1           munmap
  0.46    0.000204          68         3           brk
  0.39    0.000171         171         1           mknodat
  0.35    0.000153         153         1           set_robust_list
  0.34    0.000149         149         1           set_tid_address
  0.34    0.000148         148         1           getrandom
  0.31    0.000135         135         1           prlimit64
  0.30    0.000132         132         1           futex
  0.07    0.000029          29         1           arch_prctl
  0.00    0.000000           0         1           execve
  0.00    0.000000           0         1           rseq
------ ----------- ----------- --------- --------- ----------------
100.00    0.043991         309       142        16 total
adithi@DESKTOP-B2HISG8:~/handson_2$ cc 19.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
fifos created sucessfully
adithi@DESKTOP-B2HISG8:~/handson_2$ ls -l | grep ^p
prw-r--r-- 1 adithi adithi     0 Sep 17 09:52 Fifo1_mknod
prw-r--r-- 1 adithi adithi     0 Sep 17 09:52 Fifo2_mkfifo
prw-r--r-- 1 adithi adithi     0 Sep 17 09:51 myfifo
prw-r--r-- 1 adithi adithi     0 Sep 17 09:52 myfifo1*/
