#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

#define COUNT_TO 20 //This program counts to 1000
#define THREADS 12 //It uses 12 threads to do the count

long long i = 0;

 void * start_counting(void *arg)
 {
  for(;;)
  {
   if (i>=COUNT_TO)// check if all Count_to have been arrived at
    {
     return NULL;
    }
     ++i;

   printf("i=%lld\n", i);
  }
 }
int main(void)
{
  int i=0;
  
  pthread_t *thread_group = malloc(sizeof(pthread_t) * THREADS); //create a thread group the size of THREADS
  
  for (i=0; i<THREADS; ++i)
   {
    pthread_create(&thread_group[i], NULL, start_counting, NULL); //Start all threads to begin work
   }
  
  for (i=0; i<THREADS; ++i)
   {
    pthread_join(thread_group[i], NULL); // wait for all threads to finish
   }
  return EXIT_SUCCESS;
}