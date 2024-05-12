#include <stdio.h>

int process[3] = {1, 2, 3};
int incoming[3] = {100,231,249};
int memory[3] = {350,200,300};
int remaining[3] = {350,200,300};

void NextFit(){
    printf("P\tIncoming\tMemoryBlock\n");
    int prev=-1;
    for(int i=0; i<3; i++){
        printf("P%d\t%d\t", process[i], incoming[i]);
        for(int j=(prev+1)%3; j<3; j++){
            if(incoming[i]<=remaining[j]){
                printf("%d", memory[j]);
                printf("\n");
                remaining[j] -= incoming[i];
                prev=j;
                break;
            }
        }
    }
}

int main(){
    NextFit();
    return 0;
}