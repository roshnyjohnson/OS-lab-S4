#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
struct semaphore  {
    int value;
};

/*struct semaphore  empty={10};
struct semaphore  full={0};
struct semaphore  mutex={1};*/

void wait(struct semaphore*s)
{
    while(s->value<=0);
        s->value--;
}
void signal(struct semaphore*s)
{
    s->value++;
}

struct semaphore  empty={10};
struct semaphore  full={0};
struct semaphore  mutex={1};

int count=0;
int buffer[10];
void *producer(void*arg)
{int item=1;
while(1){
    //int item=1;
    wait(&empty);
    wait(&mutex);

    buffer[count]=item;
    printf("the produced item is %d\n",item);
    count++;
    item++;

    signal(&mutex);//exit cs
    signal(&full);//increase full slots

    sleep(1);}
}

void *consumer(void*arg)
{while(1){
    wait(&full);
    wait(&mutex);

    count--;
    printf("the consumed item is %d\n",buffer[count]);


    signal(&mutex);
    signal(&empty);

    sleep(2);}
}
int main()
{
    pthread_t prod,cons;
    pthread_create(&prod,NULL,producer,NULL);
    pthread_create(&cons,NULL,consumer,NULL);

    pthread_join(prod,NULL);
    pthread_join(cons,NULL);

    return 0;

}

