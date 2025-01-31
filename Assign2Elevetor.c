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
    int floor;
    int secs = 2;

    printf("Stare on the wall and choose the elevator you're using either 1 or 2\n");
    scanf("%d", &elevator[2]);
    if (elevator[0]== 1)
    {
        printf("Press 1 to open elevator: ");
        scanf("%d", &OpenElavator);
        sleep(2);
        if(OpenElavator == 1)
        {
            for (int i = 1; i <= 8; i++)
            {
            floor = floors[i];
            }
            printf("How many are you?\n");
            scanf("%d", &MaxPeople);
            elevator[0] = MaxPeople;
            if (elevator[0] <= 5)
            {
                printf("choose the floors to go: ");
                scanf("%d", &floor);
                if (floor == 2)
                {
                    printf("Arrived to the second floor\n\n");
                }
                else if (floor == 3)
                {
                    printf("Arrived to the third floor\n\n");
                }
                else if (floor == 4)
                {
                    printf("Arrived to the fourth floor\n\n");
                }
                else if (floor == 5)
                {
                    printf("Arrived to the firth floor\n\n");
                }
                else if (floor == 6)
                {
                    printf("Arrived to the sixth floor\n\n");
                }
                else if (floor == 7)
                {
                    printf("Arrived to the seventh floor\n\n");
                }
                else if (floor == 8)
                {
                    printf("Arrived to the eighth floor\n\n");
                }
                else
                {
                    printf("wrong floor Number\n\n");
                }
            }
            else
            {
                printf("you are above five people, only five people or below are allowed to use elevator\n\n");
            } 
        }
        else
        {
            printf("you didn't press one\n\n");
        }
    }
    else if (elevator[1]==2)
    {
        elevetor();
    }
    else
    {
        printf("you haven't chosen yet the elevetor");
    }
    sleep(5);
}
// void *elevetor1()
// {
//     // srand(time(0));
//     int floors[8] = {1, 2, 3, 4, 5, 6, 7, 8};
//     int elevator[2] = {1, 2};
//     int MaxPeople;
//     int OpenElavator = 1;
//     int ClosedElavator= 0;
//     int floor;
//     int secs = 2;

//     printf("Stare on the wall and choose the elevator you're using either 1 or 2\n");
//     scanf("%d", &elevator[2]);
//     if (elevator[0]== 1)
//     {
//         printf("Press 1 to open elevator: ");
//         scanf("%d", &OpenElavator);
//         sleep(2);
//         if(OpenElavator == 1)
//         {
//             for (int i = 1; i <= 8; i++)
//             {
//             floor = floors[i];
//             }
//             printf("How many are you?\n");
//             scanf("%d", &MaxPeople);
//             elevator[0] = MaxPeople;
//             if (elevator[0] <= 5)
//             {
//                 printf("choose the floors to go: ");
//                 scanf("%d", &floor);
//                 if (floor == 2)
//                 {
//                     printf("Arrived to the second floor\n\n");
//                 }
//                 else if (floor == 3)
//                 {
//                     printf("Arrived to the third floor\n\n");
//                 }
//                 else if (floor == 4)
//                 {
//                     printf("Arrived to the fourth floor\n\n");
//                 }
//                 else if (floor == 5)
//                 {
//                     printf("Arrived to the firth floor\n\n");
//                 }
//                 else if (floor == 6)
//                 {
//                     printf("Arrived to the sixth floor\n\n");
//                 }
//                 else if (floor == 7)
//                 {
//                     printf("Arrived to the seventh floor\n\n");
//                 }
//                 else if (floor == 8)
//                 {
//                     printf("Arrived to the eighth floor\n\n");
//                 }
//                 else
//                 {
//                     printf("wrong floor Number\n\n");
//                 }
//             }
//             else
//             {
//                 printf("you are above five people, only five people or below are allowed to use elevator\n\n");
//             } 
//         }
//         else
//         {
//             printf("you didn't press one\n\n");
//         }
//     }
//     else if (elevator[1]==2)
//     {
//         elevetor();
//     }
//     else
//     {
//         printf("you haven't chosen yet the elevetor");
//     }
//     sleep(5);
// }
int main()
{
    pthread_t ele1;
    // pthread_t ele2;
    for (int n = 2; n <= 8; n++)
    {
        if ((pthread_create(&ele1, NULL, &elevetor, NULL))!= 0)
        {
            return 1;
        }
        // if ((pthread_create(&ele2, NULL, &elevetor1, NULL)) !=0)
        // {
        //     return 100;
        // }
        if ((pthread_join(ele1, NULL)) != 0)
        {
            return 2;
        }
        // if ((pthread_join(ele2, NULL)) != 0)
        // {
        //     return 1000;
        // }
    }
}