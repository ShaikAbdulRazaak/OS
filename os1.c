#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#include<semaphore.h>
void *fun();
int i,n;
const int x=(rand()%n);
int main()
{
 pthread_t t[10000];
 scanf("%d",&n);
 for(i=1;i<=n;i++)
 {
 	pthread_create(&t[i],NULL,&fun,NULL);
 	pthread_join(t[i],NULL);
 }
	
 	printf("The ticket number generated randomly is %d\n",x);
	printf("%d\n",x);
}
void *fun()
	{
		printf("%d",x);
	}
