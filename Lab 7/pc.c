#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define N 5

int b[N];
int i = 0, o = 0;

sem_t e, f;
pthread_mutex_t m;

void *p(void *arg) {
    int x;
    for (int k = 0; k < 10; k++) {
        x = rand() % 100;

        sem_wait(&e);
        pthread_mutex_lock(&m);

        b[i] = x;
        printf("P:%d @%d\n", x, i);
        i = (i + 1) % N;

        pthread_mutex_unlock(&m);
        sem_post(&f);
    }
    return NULL;
}

void *c(void *arg) {
    int x;
    for (int k = 0; k < 10; k++) {
        sem_wait(&f);
        pthread_mutex_lock(&m);

        x = b[o];
        printf("C:%d @%d\n", x, o);
        o = (o + 1) % N;

        pthread_mutex_unlock(&m);
        sem_post(&e);
    }
    return NULL;
}

int main() {
    pthread_t t1, t2;

    sem_init(&e, 0, N);
    sem_init(&f, 0, 0);
    pthread_mutex_init(&m, NULL);

    pthread_create(&t1, NULL, p, NULL);
    pthread_create(&t2, NULL, c, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    sem_destroy(&e);
    sem_destroy(&f);
    pthread_mutex_destroy(&m);

    return 0;
}
