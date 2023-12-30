#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 10 
#define n1 3  
#define m1 3  
#define n2 3 
#define m2 3 

// Matrices
int B[n1][m1];
int C[n2][m2];
int A[n1][m2];

// Tampon
int T[N];

// Mutex et Sémaphores
pthread_mutex_t mutex;
sem_t empty;
sem_t full;


void producer(void) {
    int item;

    for (int i = 0; i < n1; ++i) {
        item = produce(i);
        sem_wait(&empty);  
        pthread_mutex_lock(&mutex);
        // Section critique
        insert_item(i, item);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);  
    }
}

// Consommateur
void consumer(void) {
    int item;
    while (1) {
        sem_wait(&full); 
        pthread_mutex_lock(&mutex);
        // Section critique
        item = remove_item();
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);  
        consume(item);
    }
}

int main() {
 
    initializeMatrices();
    initializeBuffer();


    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);

    pthread_t producerThread, consumerThread;
    pthread_create(&producerThread, NULL, (void *)producer, NULL);
    pthread_create(&consumerThread, NULL, (void *)consumer, NULL);


    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

  
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

