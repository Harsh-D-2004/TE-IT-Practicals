#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>

#define MaxItems 5
#define BufferSize 5

sem_t empty;
sem_t full;
int in = 0;
int out = 0;
int buffer[BufferSize];
pthread_mutex_t mutex;

void *producer(void * pno){

	int item = 0;
	for(int i = 0 ; i < MaxItems ; i++){
		
		item = rand();
		sem_wait(&empty);
		pthread_mutex_lock(&mutex);
		buffer[in] = item;
		printf("Producer %d: Insert Item %d at %d\n", *((int *)pno), buffer[in], in);
		in = (in+1)%BufferSize;
		pthread_mutex_unlock(&mutex);
		sem_post(&full);
	}

}

void *consumer(void * cno){

	int item = 0;
	for(int i = 0 ; i < MaxItems ; i++){
		sem_wait(&full);
		pthread_mutex_lock(&mutex);
		int item = buffer[out];
		printf("Consumer %d: Removed Item %d at %d\n", *((int *)cno), buffer[out], out);
		out = (out+1)%BufferSize;
		pthread_mutex_unlock(&mutex);
		sem_post(&empty);
	}

}

int main(){
	
	pthread_t prod[5] , con[5];
	pthread_mutex_init(&mutex , NULL);
	sem_init(&empty , 0 , BufferSize);
	sem_init(&full , 0 , 0);
	
	int cnt[5] = {1 , 2 , 3 , 4 , 5};
	
	for(int i = 0 ; i < 5 ; i++){
		pthread_create(&prod[i] , NULL , producer , (void *)&cnt[i]);
	}
	
	for(int i = 0 ; i < 5 ; i++){
		pthread_create(&con[i] , NULL , consumer , (void *)&cnt[i]);
	}
	
	for(int i = 0 ; i < 5 ; i++){
		pthread_join(prod[i] , NULL);
	}
	
	for(int i = 0 ; i < 5 ; i++){
		pthread_join(con[i] , NULL);
	}
	
	pthread_mutex_destroy(&mutex);
	sem_destroy(&empty);
	sem_destroy(&full);

	return 0;
}
























