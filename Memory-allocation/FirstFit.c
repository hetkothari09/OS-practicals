#include <stdio.h>

int incoming[3] = {120, 30, 99};
int memory[3] = {100, 150, 200};
int remaining[3] = {100, 150, 200};
int process[3] = {1, 2, 3};

void FirstFit(){
    printf("P\t Incoming\t Memory Block\n");
    for(int i=0; i<3; i++){
        printf("P%d\t%d\t", process[i], incoming[i]);
        for(int j=0; j<3; j++){
            if(incoming[i]<=remaining[j]){
                printf("%d", memory[j]);
                printf("\n");
                remaining[j]-=incoming[i];
                break;
            }
        }
    }
}

int main(){
    FirstFit();
    return 0;
}