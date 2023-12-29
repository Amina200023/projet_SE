#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 10  // Taille du tampon
#define n1 3  // Nombre de lignes de B
#define m1 3  // Nombre de colonnes de B
#define n2 3  // Nombre de lignes de C
#define m2 3  // Nombre de colonnes de C

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

// Producteur
void producer(void) {
    int item;
    // Boucle pour chaque ligne de la matrice résultante A
    for (int i = 0; i < n1; ++i) {
        item = produce(i);
        sem_wait(&empty);  // Attente d'une place libre
        pthread_mutex_lock(&mutex);
        // Section critique
        insert_item(i, item);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);  // Il y a une place remplie en plus
    }
}

// Consommateur
void consumer(void) {
    int item;
    while (1) {
        sem_wait(&full);  // Attente d'une place remplie
        pthread_mutex_lock(&mutex);
        // Section critique
        item = remove_item();
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);  // Il y a une place libre en plus
        consume(item);
    }
}

// Fonction principale
int main() {
    // Initialisation des matrices et du tampon (à compléter)
    initializeMatrices();
    initializeBuffer();

    // Initialisation des mutex et sémaphores
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);

    // Création des threads (à compléter)
    pthread_t producerThread, consumerThread;
    pthread_create(&producerThread, NULL, (void *)producer, NULL);
    pthread_create(&consumerThread, NULL, (void *)consumer, NULL);

    // Attente des threads (à compléter)
    pthread_join(producerThread, NULL);
    pthread_join(consumerThread, NULL);

    // Destruction des mutex et sémaphores
    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}

