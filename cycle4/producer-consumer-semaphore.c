#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];
int buffer_index;
sem_t full_sem;
sem_t empty_sem;
pthread_mutex_t mutex;

void insert_item(int item) {
    buffer[buffer_index++] = item;
}

int remove_item() {
    return buffer[--buffer_index];
}

void *producer(void *arg) {
    int item;
    while (1) {
        item = rand() % 100; // Produce a random item
        sem_wait(&empty_sem);
        pthread_mutex_lock(&mutex);
        insert_item(item);
        printf("Producer produced item %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&full_sem);
    }
}

void *consumer(void *arg) {
    int item;
    while (1) {
        sem_wait(&full_sem);
        pthread_mutex_lock(&mutex);
        item = remove_item();
        printf("Consumer consumed item %d\n", item);
        pthread_mutex_unlock(&mutex);
        sem_post(&empty_sem);
    }
}

int main() {
    pthread_t producer_thread, consumer_thread;

    // Initialize Semaphores and Mutex
    sem_init(&full_sem, 0, 0);
    sem_init(&empty_sem, 0, BUFFER_SIZE);
    pthread_mutex_init(&mutex, NULL);

    // Create Producer and Consumer Threads
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    // Wait for Threads to Complete
    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);

    // Clean Up Semaphores and Mutex
    sem_destroy(&full_sem);
    sem_destroy(&empty_sem);
    pthread_mutex_destroy(&mutex);

    return 0;
}
