#include <stdio.h>
#include <stdlib.h>

int buffer[50];
int n = 8;
int empty = 8;
int in=0;
int out=0;
int semaphore = 1;
int full=0;

void Producer(int item){
    semaphore--;
    if(full<n && semaphore==0){
        empty--;
        buffer[in] = item;
        printf("%d entered\n", item);
        in = (in+1)%n;
        full++;
    }
    else{
        printf("Cannot produce");
    }
    semaphore++;
}

void Consumer(){
    semaphore--;
    if(empty!=n && semaphore==0){
        full--;
        int item = buffer[out];
        buffer[out] = 0;
        printf("item: %d \n", item);
        out = (out+1)%n;
        printf("%d left \n", item);
        empty++;
    }
    else{
        printf("Cannot consume");
    }
    semaphore++;
}

void main()
{
    Consumer();
    Producer(1);
    Producer(9);
    Producer(8);
    Producer(7);
    Producer(5);
    Producer(3);
    Consumer();

    for(int i=0; i<n; i++){
        printf("%d", buffer[i]);
    }
}
