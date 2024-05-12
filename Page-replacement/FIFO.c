#include <stdio.h>
#define n 4

int frame[n];
int pages[14] = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 2, 3};

void main(){
    int hit = 0;
    int miss = 0;
    int k = 0;
    int pageFound;

    for(int i=0; i<n; i++){
        frame[i] = -1;
    }

    for(int i=0; i<14; i++){
        pageFound = 0;
        for(int j=0; j<n; j++){
            if(frame[j]==pages[i]){
                hit++;
                pageFound=1;
                break;
            }
        }
        if(!pageFound){
            miss++;
            frame[k]=pages[i];
            k=(k+1)%n;
        }
        for(int z=0; z<n; z++){
            printf("%d ", frame[z]);
        }
        printf("\n");
    }
    printf("Hits:%d\tMiss:%d", hit, miss);
}