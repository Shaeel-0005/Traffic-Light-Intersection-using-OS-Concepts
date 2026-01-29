#include <iostream>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <cstdlib>
#include <ctime>

using namespace std;

#define ROADS 4
#define PASSES 2

sem_t intersection;
pthread_mutex_t printMutex;

void* road(void* arg) {
    int id = *(int*)arg;

    for (int i = 1; i <= PASSES; i++) {

        // Random arrival
        sleep(rand() % 3 + 1);

        pthread_mutex_lock(&printMutex);
        cout << "🔴 Road " << id << " : RED light (waiting)" << endl;
        pthread_mutex_unlock(&printMutex);

        // Wait for green
        sem_wait(&intersection);

        pthread_mutex_lock(&printMutex);
        cout << "🟢 Road " << id << " : GREEN light (passing)" << endl;
        pthread_mutex_unlock(&printMutex);

        sleep(1); // crossing intersection

        pthread_mutex_lock(&printMutex);
        cout << "⚪ Road " << id << " : EXIT intersection\n" << endl;
        pthread_mutex_unlock(&printMutex);

        sem_post(&intersection);
    }

    pthread_exit(NULL);
}

int main() {
    srand(time(NULL));

    pthread_t t[ROADS];
    int ids[ROADS];

    sem_init(&intersection, 0, 1);
    pthread_mutex_init(&printMutex, NULL);

    for (int i = 0; i < ROADS; i++) {
        ids[i] = i + 1;
        pthread_create(&t[i], NULL, road, &ids[i]);
    }

    for (int i = 0; i < ROADS; i++) {
        pthread_join(t[i], NULL);
    }

    sem_destroy(&intersection);
    pthread_mutex_destroy(&printMutex);

    cout << "✅ Traffic Control Simulation Finished" << endl;
    return 0;
}
