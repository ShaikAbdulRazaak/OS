#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
void *fun();
int i,n;
static int winner = 0;
sem_t s;
int main()
{
 sem_init(&s,1,1);
 int a[50];
 for(int i=0;i<50;i++)
{
 winner = ((rand()%50-1)+ 1);
 printf("\nThe ticket number generated randomly is %d\n",winner);
 pthread_t t[100];
 a[i] = winner;
 pthread_create(&t[winner],NULL,&fun,NULL);
 pthread_join(t[winner],NULL);
}
printf("\nLottery in order :");
for (int j=0;j<50;j++)
	printf("%d  ",a[j]);

}
void *fun()
	{
		sem_wait(&s);
		printf("\nThis ticket %d the winner and is in critical section for 20 milliseconds\n",winner);
		sleep(.2);
		sem_post(&s);
	}

