// Author: AREEB AHMED FA19_BSE_022 SECTION B


#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/sem.h>
#include<errno.h>
#include<pthread.h>
#include<string.h>
#include<math.h>

#define SEMKEY 456

union semun
{
	struct semid_ds *buf;		/* buffer for IPC_STAT,IPC_SET */
	unsigned short *array;		/* array for GETALL, SETALL */
	struct seminfo *__buf;		/* buffer for IPC_INFO(Linux-specific) */
};


void *philospher_thread(void *data)		/*function for thread*/
{
	int a = *((int *)data);
	int delay1,delay2,sem_id;
	struct sembuf sops[2];
	union semun arg;
	unsigned short chopstics[2];		/* 2 chopstics for 1 philospher*/
	sem_id = semget(SEMKEY,2,0666);	/*to get semaphore id*/
	if(sem_id < 0)
		perror("can't get semaphore");
	else
	{
		arg.array = chopstics;
		sops[0].sem_num = a;
		sops[0].sem_flg = 0;
		
		sops[1].sem_num = (a+1)%5;
		sops[1].sem_flg = 0;
		while(1)
		{
			sops[0].sem_op = -1;	/*decrement after getting chopstic*/
			sops[1].sem_op = -1;
			
			printf("philospher # %d wants to eat\n",a);
			
			if(semop(sem_id,sops, 2)<0)		/* "all or none" will be applyed. if value is greater than 0 */
				perror("semop error");				/*then they can pick a chopstic*/
			
				
			printf("philospher # %d going to eat\n",a);
			
			for(delay1 = rand()%3000;delay1>0;delay1--)		/*for delay in program*/	
				for(delay2 = 0; delay2<90000;delay2++)
					abs(delay2*.0000985);
					
					
			sops[0].sem_op = 1;
			sops[1].sem_op = 1;
			if(semop(sem_id,sops, 2)<0)
				perror("semop error");
			printf("philospher # %d done eating, now going to think\n",a);
			for(delay1 = rand()%3000;delay1>0;delay1--)		/*for delay in program*/
				for(delay2 = 0; delay2<90000;delay2++)
					abs(delay2*.000098);
			
			
			
		}
	
	}

}
int main(int argc, char *argv[])
{

	int err, counter;
	int sem_id;
	union semun arg;
	unsigned short chopstics[5];
	sem_id = semget(SEMKEY,5,(IPC_CREAT|IPC_EXCL|0666));
	if(sem_id < 0)
		perror("can't create semaphore");
	else 
	{
		chopstics[0]=1;
		chopstics[1]=1;
		chopstics[2]=1;
		chopstics[3]=1;
		chopstics[4]=1;
		arg.array = chopstics;
		if(semctl(sem_id,0,SETALL, arg) == -1)
		{
			perror("semctl");
			exit(1);
		}
	}
	
	pthread_t tid[5];				/*thread array*/
	int thread_array[5];
	thread_array[0] = 0;
	thread_array[1] = 1;
	thread_array[2] = 2;
	thread_array[3] = 3;
	thread_array[4] = 4;
	
	for(counter = 0 ; counter< 5; counter++)
	{
		if(err = pthread_create((&tid[counter]), NULL , philospher_thread, &thread_array[counter]))
		{
			fprintf(stderr,"Failed to create thread");
		}
	}
	
	for(counter = 0 ; counter< 5; counter++)
	{
		if(err = pthread_join(tid[counter], NULL))
			fprintf(stderr,"Failed to join thread\n");
	}
	return 0;
}

	
	
	
	
