#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> //Header file for sleep(). man 3 sleep for details.
#include <pthread.h>
#include <time.h>
#include<sys/types.h>

int passengerSize;
int OpenEl;
pthread_mutex_t mutex;

void *waitingPassengers(void *vargp) {
    
    
    srand(time(0));
    passengerSize = (rand() % 8) + 1;

    do{
    printf("press 1 to open elevator: ");
    scanf("%d", &OpenEl);
    printf("\n");
    if (OpenEl == 1){
    printf("Passangers at ground floor are: %d\n", passengerSize);
    printf("\n");
    
    for (int i = 1;i<passengerSize+1;i++) {
        
        if (i <= passengerSize && i < 6){
        printf("Passenger %d has entered the elevator\n", i);
        }
        if (i > 5) {
            printf("Reached maximum capacity\n");
            break;
        }
    }
    }
    } while(OpenEl != 1); 
    printf("\n\n");//  we will call a function to close the elevator

}

void *myElevator(void *vargp)
{
    if (passengerSize > 5) {
        int temp = passengerSize - 5;
        passengerSize -= temp;
    }
    printf("Total number of passengers in elevator is: %d\n", passengerSize);


    //THE PASSENGERS CHOICES
    int floorChoices[5];
    int lower = 2, upper = 8;
    srand(time(0));
    for (int i=1; i <= passengerSize; i++) {

        int levelChoice;

        printf("Passenger %d, Please choose the floor between 2 and 8: ", i);
        scanf("%d", &levelChoice);

        while (1) {
                if (levelChoice > 8 || levelChoice < 2) {
                    printf("Invalid floor\n");
                    printf("Passenger %d, Please choose the floor between 2 and 8: ", i);
                    scanf("%d", &levelChoice);
                }else {
                    break;
                }
        }

        printf("Passenger %d has chosen floor %d\n\n", i, levelChoice);
        floorChoices[i] = levelChoice;
        
    }




    printf("\n\n");

    printf("<=========================Elevator in motion===========================>\n\n");

    int Destination = 0;
    for (int i=2; i<=8; i++) {
        printf("<===Reaching floor %d===>\n\n", i);
        sleep(2);

        int leftPassengers = 0;
        for (int x=0; x<=5; x++) {

            if (floorChoices[x] >= Destination && i == floorChoices[x]) {
                printf("The floor choice is: %d\n", floorChoices[x]);
                
                Destination = floorChoices[x];
                printf("Passenger %d has now arrived at floor %d\n", x, Destination);
                sleep(5);
                passengerSize --;
                leftPassengers ++;
            } 
        }
        printf("%d passengers exited on this floor \n", leftPassengers);
        
        printf("The number of remaining passengers: %d\n", passengerSize);

        if(i == 8) {
            printf("\nThe elevator has reached its last destination!\n\n");
        } else {
            printf("The elevator is still moving....\n\n");
        }

    }

	return NULL;
}

int main()
{
    // DEFINING THE TWO THREADS TO USE [2 ELEVATORS]
    
	pthread_t thread_id, thread2;
	pthread_mutex_init(&mutex, NULL);

	
	// CREATING ONE THREAD [AN ELEVATOR]
    pthread_create(&thread_id, NULL, waitingPassengers, NULL);
    pthread_join(thread_id, NULL);

    pthread_create(&thread2, NULL, myElevator, NULL);
    pthread_join(thread2, NULL);

    //we will call a function to close the elevator
    pthread_mutex_destroy(&mutex);

	exit(0);
}