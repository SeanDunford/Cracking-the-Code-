/* Sean Dunford - sdunford - u66807525 - ass3*/

#include <stdio.h>            // console I/O
#include <sys/types.h>        //specal types
#include <sys/ipc.h>          //inter process comm 
#include <sys/shm.h>          //shared mem api
#include <stdlib.h>           //std calls
#include <unistd.h>           //used for std calls
#include <stdbool.h>          //used for bools
#include <sys/sem.h>          //used for semaphores

#define SHMKEY ((key_t) 7891) // Shared MEM Key
#define SEMKEY ((key_t) 400L)           // Semaphore Key
#define NSEMS 1                         // number of semaphores being created

typedef struct                          //Structure of sharedmemory
{
  int value;
}   shared_mem; 

shared_mem *total;                      //Pointer to shared memory

typedef union                           //Union for Semaphore arguments
{
  int val;
  struct semid_ds *buf;
  ushort *array;
}   semunion;

int sem_id;                             //semaphore ID
static struct sembuf OP = {0,-1,0};     //some sem buffer stuff
static struct sembuf OV = {0,1,0};      //some sem buffer stuff
struct sembuf *P =&OP;                  //Pointer to above buffer
struct sembuf *V =&OV;                  //Pointer to above buffer

//wait/signal functions?
int SignalPop()                               //Declares local status
{ 
  int status;                 
  status = semop(sem_id, P,1);          //sets status equal to retun
  return status;                        //Returns status
}
int WaitVop()                               //Declares local status 
{ 
  int status;
  status = semop(sem_id, V,1);          //sets status equal to return
  return status;
}

process1 ()
{
  int k = 0;
  int test = 0; 

  while (k < 100000)
    {
      k++;
      SignalPop();
      total->value = total->value + 1;
       //if(shm is == 600,000 print stuff
      WaitVop(); 
    }
  printf ("From process1: counter = %d. \n", total->value);
}

process2 ()
{
  int k = 0;
      
  while (k < 200000)
    {
      k++;
      SignalPop(); 
      total->value = total->value + 1;
     //if(shm is == 600,000 print stuff
      WaitVop();
    }
  printf ("From process2: counter =  %d.\n", total->value);
  
}

process3 ()
{
  int k = 0;
  while (k < 300000)
    {
      k++;
      SignalPop(); 
      total->value = total->value + 1;
       //if(shm is == 600,000 print stuff
       WaitVop(); 
    }

  printf ("From process3: counter =  %d.\n", total->value);
  
}

int main()
{  
  int   shmid;                          //id used for shared memory. In order to attach shared mem to a process we must have the shmid of the shared mem
  int   pid1;                           //id of first process only valid in main process
  int   pid2;                           //id of second process
  int   pid3;                           //id of third process only valid in main process
  int   ID;                             //
  int status;                           //
  int test; 


  char *shmadd;                         //
  shmadd = (char *) 0;                  //

  int semnum =0;
  int value, value1;
  semunion semctl_arg;
  semctl_arg.val =1;
                                        // Create semaphores 



                                        /* Create and connect to a shared memory segmentt*/

  if ((shmid = shmget (SHMKEY, sizeof(int), IPC_CREAT | 0666)) < 0)
    {
      perror ("shmget");
      exit (1);
    }//creates shared mem with 666 - read write permissions and tests to see if it was successful

 
 if ((total = (shared_mem *) shmat (shmid, shmadd, 0)) == (shared_mem *) -1)
    {
      perror ("shmat");
      exit (0);
    }// attaches shared memory to main process and tests to see if it was sucessful
sem_id = semget(SEMKEY, NSEMS, IPC_CREAT | 0666);
if(sem_id < 0) printf("Error in creating the semaphore.\n");



                // Initialize semaphore 
value1 =semctl(sem_id, semnum, SETVAL, semctl_arg);

  total->value = 0; //
  if ((pid1 = fork()) == 0)//fork process 1 then run it
    {
     process1(); 
     shmdt(shmid);
     exit(0);  
  }
  if ((pid1 != 0) && (pid2 = fork()) == 0)//fork and run process 2
    { 
     process2();
     shmdt(shmid);
     exit(0);  
   }
  if ((pid1 != 0) && (pid2 != 0) && (pid3 = fork()) == 0)//fork and run p3
   {    process3();
     shmdt(shmid);
     exit(0);  
   }

// wait loop and release Shared memory 
  wait(); 
  wait(); 
  wait(); 

   printf("\n");
   printf("Process with PID %d has exited \n", pid1);
   printf("Process with PID %d has exited \n", pid2);
   printf("Process with PID %d has exited \n", pid3);



 if ((shmctl (shmid, IPC_RMID, (struct shmid_ds *) 0)) == -1)//clean up shared mem
  {
    perror ("shmctl");
    exit (-1);
  }//error if unsuccessful


value =semctl(sem_id, semnum, GETVAL, semctl_arg);
if (value < 1) printf("Eror detected in SETVAL.\n");
// De-allocate semaphore 
semctl_arg.val = 0;
status =semctl(sem_id, 0, IPC_RMID, semctl_arg);
if( status < 0) printf("Error in removing the semaphore.\n");


  printf("\t End of Simulation \n\n"); 
exit(0);//replaced return with exit to match  
}