#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <time.h>


int passengers[5];
pthread_mutex_t mutex;

void *myElevator(void *vargp)
{
    // CALCULATING THE SIZE OF ARRAY CONTAINING THE FIRST 5 PASSENGERS
    size_t passengerSize = sizeof(passengers)/sizeof(passengers[0]);
    //printf("this is size of passenger array: %d\n\n", passengerSize);


    // ALLOW PASSENGERS TO ENTER THE ELEVATOR

    int counter = 0; //number of passengers
    printf("Opening the elevator\n\n");

    for (int i = 1; i <= passengerSize; i++) {
        pthread_mutex_lock(&mutex);

        int input;

        printf("Please enter '1' to allow a person to enter the elevator and any other digit otherwise: ");
        scanf("%d", &input);


        if (input != 1 && counter == 0) {
            exit(0);
        } else if (input != 1) {
            break;
        } else {
            counter++;
        }


        printf("A Passenger %d has entered the elevator\n\n", i );
        //counter++;

        pthread_mutex_unlock(&mutex);
    }
    printf("the counter is now %d", counter);

    printf("\n\n");
    sleep(1); // JUST VISUALISATION NOTHING MORE
\

    //THE PASSENGERS CHOICES
    int floorChoices[5];
    int lower = 2, upper = 8;
    srand(time(0));
    for (int i=0; i<counter; i++) {
        int levelChoice;

        printf("Passenger %d, Please choose the floor between 2 and 8: ", i+1);
        scanf("%d", &levelChoice);

        while (1) {
                if (levelChoice > 8 || levelChoice < 2) {
                    printf("Invalid floor\n");
                    printf("Passenger %d, Please choose the floor between 2 and 8: ", i+1);
                    scanf("%d", &levelChoice);
                }else {
                    break;
                }
        }

        //int r = (rand() % (upper - lower + 1)) + lower; // A FORMULA FOR A RANDOM NUMBER BETWEEN 2 AND 8
        printf("Passenger %d has chosen floor %d\n\n", i+1, levelChoice);
        //sleep(2);
        floorChoices[i] = levelChoice;
    }

    printf("\n\n");

    /*
    // REMOVING 5 PASSENGERS ACCORDINGLY
    size_t choicesSize = sizeof(floorChoices)/sizeof(floorChoices[0]);
    for (int i=2; i<=8; i++) {
        printf("Reaching floor %d\n", i);

        if this i == the r, passenger (# == i) chose the passenger is removed
        for now we have to store the passenger and his choice floor together

        sleep(2);
    }
    int floorsPassed[4];
    */


    //going through the floors
    int compare = 0;

    for (int i=2; i<=8; i++) {
        printf("Reaching floor %d\n", i);
        sleep(2);
        int someOtherChecker = 0;
        int leftPassengers = 0;
        for (int x=0; x<5; x++) {

            if (floorChoices[x] >= compare && i == floorChoices[x]) {
                compare = floorChoices[x];
                printf("Passenger %d has now arrived at floor %d\n", x+1, compare);
                sleep(2);
                counter --;
                leftPassengers ++;
                someOtherChecker ++;

            }

        }
        printf("The number of remaining passengers: %d\n", counter);

        printf("%d passengers exited on this floor \n", leftPassengers);
        // leftPassengers = 0;

        if(i == 8) {
            printf("\nThe elevator has reached its last destination!\n\n");
        } else if (someOtherChecker != 0){
            printf("The elevator stopped at this floor temporarily....\n\n");
        } else {
            printf("The elevator is still moving....\n\n");
        }

    }
	//sleep(1);
	//printf("Printing GeeksQuiz from Thread \n");


	return NULL;
}

int main()
{
    // DEFINING THE TWO THREADS TO USE [2 ELEVATORS]
	pthread_t thread_id, thread2;
	pthread_mutex_init(&mutex, NULL);

	/*
	printf("Before Thread\n");
	int passengers[4];\
	*/

	// CREATING ONE THREAD [AN ELEVATOR]
    pthread_create(&thread_id, NULL, myElevator, NULL);

    /*
	int i;
	for (i = 1; i <= 5; i++) {
        pthread_create(&thread_id, NULL, myElevator, NULL);
        passengers[i] = i;
    }
    */

    // JOINING THE THREAD
    pthread_join(thread_id, NULL);

    /*
    for (i = 1; i <= 5; i++) {
        pthread_join(thread_id, NULL);
    }
	pthread_create(&thread_id, NULL, myThreadFun, NULL);
	pthread_create(&thread2, NULL, myThreadFun, NULL);
	pthread_join(thread_id, NULL);
	pthread_join(thread2, NULL);
	printf("After Thread\n");
	printf(myElevator(NULL));
	*/

	// DESTROYING THE MUTEX
    pthread_mutex_destroy(&mutex);

	exit(0);
}