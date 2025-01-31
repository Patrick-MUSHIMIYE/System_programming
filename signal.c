#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<sys/types.h>

int main()
{

    int a;
    printf("enter value a\n");
    scanf("%d", &a);
    if (a % 2 == 0)
    {
        printf("the value is even\n");
    }
    else
    {
        printf("the value is not even\n");
    }
}