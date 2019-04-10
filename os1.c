#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
void *fun();
int i,n;
static int winner = 0;

int main()
{
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
printf("\nLottery in order : ");
for (int j=0;j<50;j++)
	printf("%d  ",a[j]);

}
void *fun()
	{
		printf("\nThis ticket %d the winner and is in critical section for 20 milliseconds\n",winner);
		sleep(.2);
	}

/*
 pthread_create(&t1,NULL,&fun,NULL);
 pthread_join(t1,NULL);
 pthread_create(&t2,NULL,&fun,NULL);
 pthread_join(t2,NULL);
 pthread_create(&t3,NULL,&fun,NULL);
 pthread_join(t3,NULL);
 pthread_create(&t4,NULL,&fun,NULL);
 pthread_join(t4,NULL);
 pthread_create(&t5,NULL,&fun,NULL);
 pthread_join(t5,NULL);*/

