/*==================================================================================
 * Name : 5.c
 * Author : Adithi P
 * Description :5. Write a program to print the system limitation of  
       a. maximum length of the arguments to the exec family of functions.  
       b. maximum number of simultaneous process per user id.  
       c. number of clock ticks (jiffy) per second.  
       d. maximum number of open files 
       e. size of a page 
       f. total number of pages in the physical memory 
       g. number of currently available pages in the physical memory.  #include<unistd.h>
  * Date: 20th September,2025
* ==================================================================================*/

#include<unistd.h>
#include<stdio.h>

int main(void){
	// man sysconf
        printf("a. maximum length of arguments to exec family of functions %ld \n",sysconf(_SC_ARG_MAX));
	 printf("b.maximum number of simultaneous process per user id %ld \n",sysconf(_SC_CHILD_MAX));
	  printf("c. number of clock ticks (jiffy) per second %ld \n",sysconf(_SC_CLK_TCK));
	   printf("d. maximum number of open files %ld \n",sysconf(_SC_OPEN_MAX));
	    printf("e. size of page %ld \n",sysconf(_SC_PAGESIZE));
	     printf("f. total number of pages in physical memory %ld \n",sysconf(_SC_PHYS_PAGES));
	      printf("g. number of currently available pages in the physical memory %ld \n",sysconf(_SC_AVPHYS_PAGES));
}
/*======================================================================================
 * Output:
 * adithi@DESKTOP-B2HISG8:~/handson_2$ cc 5.c
adithi@DESKTOP-B2HISG8:~/handson_2$ ./a.out
a. maximum length of arguments to exec family of functions 2097152
b.maximum number of simultaneous process per user id 31465
c. number of clock ticks (jiffy) per second 100
d. maximum number of open files 10240
e. size of page 4096
f. total number of pages in physical memory 2016310
g. number of currently available pages in the physical memory 1896769 */
