// c program to simulate an elavator

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
// # define MaxPeople 10
// # define elevator 1
// # define floors 8


void *elevetor()
{
    // srand(time(0));
    int floors[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int elevator[2] = {1, 2};
    int MaxPeople;
    int OpenElavator = 1;
    int ClosedElavator= 0;
    int floor; int chosenfloor;

    // pthread_mutex_t mutex;

    printf("Press 1 to open elevator: ");
    scanf("%d", &OpenElavator);
    printf("\n");
    sleep(2);
    if(OpenElavator == 1)
    {
        // pthread_mutex_lock(&mutex);
        for (int i = 1; i <= 8; i++)
        {
            floor = floors[i];
        }
        for (int passenger = 1; passenger<=5; passenger ++)
        {
            printf("passenger %d choose your destination: ", passenger);
            scanf("%d", &floor);
            chosenfloor = floor;
        }
            for (floor = 2; floor <= 8; floor++)
            {
                if (chosenfloor == 2)
                {
                    printf("arrived to second floor\n");
                }
                else if (chosenfloor == 3)
                {
                    printf("arrived to third floor\n");
                }
                else if (chosenfloor == 4)
                {
                    printf("arrived to fourth floor\n");
                }
                else if (chosenfloor == 5)
                {
                    printf("arrived to fifth floor\n");
                }
                else if (chosenfloor == 6)
                {
                    printf("arrived to sixth floor\n");
                }
                else if (chosenfloor == 7)
                {
                    printf("arrived to seventh floor\n");
                }
                else if (chosenfloor == 8)
                {
                    printf("arrived to eigth floor\n");
                }
                else
                {
                    printf("wrong floor Number\n");
                }
                sleep(2);
            }
           
    }
    else
    {
        printf("you didn't press one\n\n");
    }
    sleep(5);
    // pthread_mutex_unlock(&mutex);
}
int main()
{
    pthread_t ele1;
    // pthread_mutex_init(&mutex, NULL);
    pthread_create(&ele1, NULL, &elevetor, NULL);
    //pthread_create(&ele2, NULL, &elevetor, NULL);
    pthread_join(ele1, NULL);
    //sleep(1);
    //pthread_join(ele2, NULL);  

    // pthread_mutex_destroy(&mutex);
}