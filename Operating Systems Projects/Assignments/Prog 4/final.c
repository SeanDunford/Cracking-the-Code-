/*
 *
 *  Final Programming Assignment
 *  Operating Systems
 *
 *
 *	Purpose: To demonstrate the use of threads and semaphores
 *  
 *  Authors: Lukyan Hritsko, Sean Dunford, Mouhmad(sp?) Ibrahim(sp?)
 */


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#include <sys/types.h>
#include <unistd.h>

char array[15] = {'\00'}; //This buffer will be treated as a circular buffer
sem_t sem;
char output[151] = {'\00'}; //150 + 1(null terminator)
int overallcount = 1;

void * producer() {
	char c;
	FILE * fp;
	int count = 0;
	fp = fopen("mytest.dat", "r");

	while(1) {
		if(sem_wait(&sem) == 0) { //if statement makes sure no errors occur 
								  //with semaphore 
			if(array[count] == '\00') { 
				if(fscanf(fp, "%c", &c) == EOF || overallcount == 150) { 
					sem_post(&sem);
					count = (count + 1) % 15;
					break;
				}
				array[count] = c; //Critical sec
				overallcount++;
				//below assures count will never go above 14
				count = (count + 1) % 15;
			}
			sem_post(&sem);
		}
		else {
			perror("semaphore");
			exit(1);
		}
	}
	if(sem_wait(&sem) == 0) {
		while(1) {
			if(array[count] == '\00') {
				array[count] = '*';
				break;		
			}
			count = (count + 1) % 15;
		}
		sem_post(&sem);
	}
	else {
		perror("semaphore");
		exit(1);
	}
}

void * consumer() {
	int i;
	int count = 0;
	char temp[2] = {'\00'};
	while(1) {
		sleep(1);
		if(sem_wait(&sem) == 0) {
			temp[0] = array[count];
			if(temp[0] != '*') {
				strncat(output, temp, 1);
				array[count] = '\00';
				count = (count + 1) % 15;
			} 
			else {
				while(1) {
					temp[0] = array[count];
					if(temp[0] != '\00' && temp[0] != '*') {
						strncat(output, temp, 1);	
					}
					else {
						break;
					}
					count = (count + 1) % 15;
				}
				break;
			}
		}
		else {
			perror("semaphore");
			exit(1);
		}
		sem_post(&sem);
	}	
}


int main(int argc, char ** argv) {

	
	pthread_t thread1, thread2;
	pthread_attr_t attr[1];

	printf("1 - I am here in pid %d\n", getpid());
	fflush(stdout);

	sem_init(&sem, 1, 2); //Initializes the semaphore

	pthread_attr_init(&attr[0]);
	pthread_attr_setscope(&attr[0], PTHREAD_SCOPE_SYSTEM);


	pthread_create(&thread1, &attr[0], &producer, NULL);
	pthread_create(&thread2, &attr[0], &consumer, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);

	sem_destroy(&sem); //This destroys the semaphore used
	printf("Amount of characters read from file: %d\n", overallcount);
	fflush(stdout);
	printf("%s\n", output);
	return 0;
}
