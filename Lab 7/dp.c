#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define N 5

sem_t s[N];  

void *p(void *arg) {
    int id = *(int *)arg;

    printf("P%d thinking\n", id);
    sleep(1);

    sem_wait(&s[id]);              
    sem_wait(&s[(id + 1) % N]);    

    printf("P%d eating\n", id);
    sleep(1);

    sem_post(&s[id]);           
    sem_post(&s[(id + 1) % N]);     

    printf("P%d done\n", id);
    return NULL;
}

int main() {
    pthread_t t[N];
    int id[N];

    for (int i = 0; i < N; i++)
        sem_init(&s[i], 0, 1);

    for (int i = 0; i < N; i++) {
        id[i] = i;
        pthread_create(&t[i], NULL, p, &id[i]);
    }

    for (int i = 0; i < N; i++)
        pthread_join(t[i], NULL);

    return 0;
}
