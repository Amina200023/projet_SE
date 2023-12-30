#include <stdio.h>
#include <stdlib.h>
#include <time.h>  
#include <pthread.h>
#include <semaphore.h>

#define N 10  
#define n1 3 
#define m1 3  
#define n2 3  
#define m2 3  
#define ITERATIONS 5  // Nombre d'itérations pour le producteur et le consommateur

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


int produire(int ligne);
void inserer_element(int ligne, int element);
int retirer_element(void);
void consommer(int element);
void initialiserMatrices(void);
void initialiserTampon(void);


void *producteur(void *arg) {
    int element;
    for (int i = 0; i < ITERATIONS; ++i) {
        element = produire(i);
        sem_wait(&empty);
        pthread_mutex_lock(&mutex);
        inserer_element(i, element);
        pthread_mutex_unlock(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL);
}


void *consommateur(void *arg) {
    int element;
    for (int i = 0; i < ITERATIONS; ++i) {
        sem_wait(&full);
        pthread_mutex_lock(&mutex);
        element = retirer_element();
        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
        consommer(element);
    }
    pthread_exit(NULL);
}
int produire(int ligne) {
   
    srand(time(NULL));
    return rand();
}

void inserer_element(int ligne, int element) {

    T[ligne] = element;
}

int retirer_element(void) {

    return T[0];
}

void consommer(int element) {
   
    printf("Élément consommé : %d\n", element);
}

void initialiserMatrices(void) {

    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            B[i][j] = rand();
        }
    }

    for (int i = 0; i < n2; ++i) {
        for (int j = 0; j < m2; ++j) {
            C[i][j] = rand();
        }
    }
}

void initialiserTampon(void) {
    for (int i = 0; i < N; ++i) {
        T[i] = 0;
    }
}
// Fonction principale
int main() {
    initialiserMatrices();
    initialiserTampon();

    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, N);
    sem_init(&full, 0, 0);

    pthread_t threadProducteur, threadConsommateur;
    pthread_create(&threadProducteur, NULL, producteur, NULL);
    pthread_create(&threadConsommateur, NULL, consommateur, NULL);

    pthread_join(threadProducteur, NULL);
    pthread_join(threadConsommateur, NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);

    return 0;
}





