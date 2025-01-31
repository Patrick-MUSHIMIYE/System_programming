#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <time.h>
#include<sys/types.h>


int passengers[5];
pthread_mutex_t mutex;

void *myElevator(void *vargp)
{
    fork();

    // CALCULATING THE SIZE OF ARRAY CONTAINING THE FIRST 5 PASSENGERS
    size_t passengerSize = sizeof(passengers)/sizeof(passengers[0]);
    //printf("this is size of passenger array: %d\n\n", passengerSize);

    // ALLOW PASSENGERS TO ENTER THE ELEVATOR
    for (int i = 1; i <= passengerSize; i++) {
        pthread_mutex_lock(&mutex);
        printf("A Passenger %d has entered the elevator\n", i );
        pthread_mutex_unlock(&mutex);
    }

    printf("\n\n");
    sleep(1); // JUST VISUALISATION NOTHING MORE

    //5 PASSENGERS CHOICES
    int floorChoices[5];
    int lower = 2, upper = 8;
    srand(time(0));
    for (int i=1; i<=5; i++) {
        int r = (rand() % (upper - lower + 1)) + lower; // A FORMULA FOR A RANDOM NUMBER BETWEEN 2 AND 8
        printf("Passenger %d has chosen floor %d\n", i, r);
        sleep(1);
        floorChoices[i] = r;
    }

    printf("\n\n");

    // REMOVING 5 PASSENGERS ACCORDINGLY
    int compare = 0;
    for (int i=2; i<=8; i++) {
        printf("Reaching floor %d\n", i);
        sleep(2);
        for (int x=0; x<5; x++) {
            if (floorChoices[x] > compare && i == floorChoices[x]) {
                compare = floorChoices[x];
                printf("Passenger %d has now arrived at floor %d\n\n", x, compare);

                // If floor choices has duplicates == i, remove the duplicates


                sleep(2);
            }
        }
    }
	sleep(1);


	return NULL;
}
// passenger 1 arrived floor 2   |    passenger 3 arrived at the floor 2
// passenger 3 arrived floor 4   |    passenger 2 arrived at the floor 4
// passenger 2 arrived floor 5   |    passenger 2 arrived at the floor 5

int main()
{
    // DEFINING THE TWO THREADS TO USE [2 ELEVATORS]
	pthread_t thread1;
	pthread_mutex_init(&mutex, NULL);

	// CREATING ONE THREAD [AN ELEVATOR]
    pthread_create(&thread1, NULL, myElevator, NULL);


    // JOINING THE THREAD
    pthread_join(thread1, NULL);

	// DESTROYING THE MUTEX
    pthread_mutex_destroy(&mutex);

	exit(0);
}