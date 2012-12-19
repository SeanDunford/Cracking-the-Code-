
/*
Sean Dunford
sdunford
ass1*/

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHMKEY ((key_t) 7890)


typedef struct   //struct used as shared memory. //could probably just be an int but struct is the normal procedure so we can encapsulate data
{
  int value;
} shared_mem;

shared_mem *total;  // pointer of type shared memory labeld total




/*----------------------------------------------------------------------*
 * This function increases the value of shared variable "total"
 *  by one all the way to 120000
 *----------------------------------------------------------------------*/

process1 ()
{
  int k = 0;
 
  while (k < 120000)
    {
      k++;
      total->value = total->value + 1;
    }
  printf ("From process1 total = %d \n", total->value);
}


/*----------------------------------------------------------------------*
 * This function increases the vlaue of shared memory variable "total"
 *  by one all the way to 170000
 *----------------------------------------------------------------------*/

process2 ()
{
  int k = 0;

  while (k < 50000)
    {
      k++;
     total->value = total->value + 1;
    }
  
  printf ("From process2 total = %d\n", total->value);
  
}
/*----------------------------------------------------------------------*
 * This function increases the vlaue of shared memory variable "total"

 *  by one all the way to 200000
 *----------------------------------------------------------------------*/


process3 ()
{
  int k = 0;

  while (k < 30000)
    {
      k++;
     total->value = total->value + 1;
    }
  
  printf ("From process3 total = %d\n", total->value);
  
}
/*----------------------------------------------------------------------*
 * MAIN()
 *----------------------------------------------------------------------*/

main()
{
  int   shmid;			//id used for shared memory. In order to attach shared mem to a process we must have the shmid of the shared mem
  int   pid1;			//id of first process only valid in main process
  int   pid2;			//id of second process
  int   pid3; 			//id of third process only valid in main process
  int   ID;			//
  int	status;			//

  char *shmadd;		//
  shmadd = (char *) 0;		//

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
  
  
  total->value = 0; //

  if ((pid1 = fork()) == 0)//fork process 1 then run it
    {process1(); 
     shmdt(shmid);
     exit(0);  
	}
  
   else if (pid1 != 0)//tell main wait for p1
   {
	waitpid(pid1); 
	printf ("Parent sees process 1 finishing PID: %d\n",pid1);
	}

  if ((pid1 != 0) && (pid2 = fork()) == 0)//fork and run process 2
    { process2();
     shmdt(shmid);
     exit(0);  }
   else if (pid1 !=0 && pid2 !=0)//wait for p2
	{
	waitpid(pid2); 
	printf ("Parent sees process 2 finishing PID: %d\n",pid2);
	}

  if ((pid1 != 0) && (pid2 != 0) && (pid3 = fork()) == 0)//fork and run p3
{    process3();
     shmdt(shmid);
     exit(0);  }

   else if (pid1 !=0 && pid2 !=0 && pid3 !=0) //wait for p3
	{	
	waitpid(pid3); 
	printf ("Parent sees process 3 finishing PID: %d\n",pid2);
	shmdt(shmid);

      if ((shmctl (shmid, IPC_RMID, (struct shmid_ds *) 0)) == -1)//clean up shared mem
	{
	  perror ("shmctl");
	  exit (-1);
	}//error if unsuccessful
      printf ("\t\t  End of Program.\n");

    }
  	/*Delete next line*/
	printf("SHMID is: %d" ,shmid); 
exit(0);//replaced return with exit to match  
} 
