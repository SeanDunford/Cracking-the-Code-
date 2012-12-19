#include <stdio.h>            // console I/O
#include <sys/types.h>        //specal types
#include <sys/ipc.h>          //inter process comm 
#include <sys/shm.h>          //shared mem api
#include <stdlib.h>           //std calls
#include <unistd.h>           //used for std calls
#include <stdbool.h>          //used for bools
#include <sys/sem.h> 




void P1()
{
	printf("From Process 1: counter = 100000. \n"); 
}
void P3()
{
	printf("From Process 2: counter = 300000. \n"); 
}
void P2()
{
	printf("From Process 3: counter = 600000. \n"); 
}


int main()
{
	int pid1 = 0; 
	int pid2 = 0; 
	int pid3 = 0; 
	int stat = 42; 

  if ((pid1 = fork()) == 0)//fork process 1 then run it
    { P1(); 
     exit(0);  
  }
  if ((pid1 != 0) && (pid2 = fork()) == 0)//fork and run process 2
    { P2();
     exit(0);  
 }
  if ((pid1 != 0) && (pid2 != 0) && (pid3 = fork()) == 0)//fork and run p3
	{    P3();	
     exit(0);  
 }


 	wait(); 
 	wait(); 
 	wait(); 

   printf("\n");
   printf("Process with PID %d has exited \n", pid1);
   printf("Process with PID %d has exited \n", pid2);
   printf("Process with PID %d has exited \n", pid3);

   printf("\t End of Simulation \n");
return 0; 
 }
