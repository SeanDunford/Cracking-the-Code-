
/*
Sean Dunford
sdunford
u66807525
ass3*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <sys/sem.h>

#define SEMKEY ((key_t) 400L)
// number of semaphores being created
#define NSEMS 1

//structure
typedef struct
{
  int value;
} shared_mem
int sem_id;
typedef union{
int val;
struct semid_ds *buf;
ushort *array;
} semunion;

static struct sembuf OP = {0,-1,0};
static struct sembuf OV = {0,1,0};
struct sembuf *P =&OP;
struct sembuf *V =&OV;
//function 
int Pop()
{ 
  int status;
  status = semop(sem_id, P,1);
  return status;
}
int Vop()
{ 
  int status;
  status = semop(sem_id, V,1);
  return status;
}


int main()
{  

int semnum =0;
int value, value1;
semunion semctl_arg;
semctl_arg.val =1;
// Create semaphores 
sem_id = semget(SEMKEY, NSEMS, IPC_CREAT | 0666);
if(sem_id < 0) printf(“Error in creating the semaphore./n”);

// Initialize semaphore 
value1 =semctl(sem_id, semnum, SETVAL, semctl_arg);

value =semctl(sem_id, semnum, GETVAL, semctl_arg);
if (value < 1) printf(“Eror detected in SETVAL.\n”);

// De-allocate semaphore 
semctl_arg.val = 0;
status =semctl(sem_id, 0, IPC_RMID, semctl_arg);
if( status < 0) printf(“Error in removing the semaphore.\n”);


printf("End of Simulation /n"); 
printf("Hello"); 
exit(0);//replaced return with exit to match  
}

