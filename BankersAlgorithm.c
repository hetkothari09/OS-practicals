#include <stdio.h>
#include <stdlib.h>

int need[50][50]={
    {7,4,3},
    {21,2,2},
    {6,0,0},
    {0,1,1},
    {4,3,1}
},alloc[50][50]={
    {0, 1, 0},
    {2, 0, 0},
    {3, 0, 2},
    {2, 1, 1},
    {0, 0, 2}
};
int avail[50]={3,3,2};
int request[50] = {1,0,2};
int safeSequence[50];
int visited[50];
int ProcessRequest = 1;
int count = 0;
int resources = 3;
int n = 5;

int RequestChanges(){
    for(int i=0; i<resources; i++){
        if(request[i]<=avail[i]){
            count++;
        }
    }

    if(count==resources){
        for(int j=0; j<resources; j++){
            alloc[ProcessRequest][j] += request;
            avail[j] -= request[j];
            need[ProcessRequest][j] -= request[j];
        }
        return 1;
    }
    else{
        return 0;
    }
}

int Bankers(){
    for(int k=0; k<n; k++){
        for(int i=0; i<n; i++){
            int temp;
            for(int j=0; j<resources; j++){
                if(need[i][j]<=avail[j] && visited[i]!=1){
                    temp++;
                }
            }
            if(temp==resources){
            safeSequence[count]=i;
            visited[i]=1;
            count++;
            }
            for(int j=0; j<resources; j++){
                avail[j] += alloc[i][j];
            }
        }
    }
}


void main()
{
    int newRequest = RequestChanges();
    Bankers();

    if(newRequest==0){
        printf("Request denied!");
    }
    else if(count==n && newRequest==1){
        printf("Safe sequence is: ");
        for(int i=0; i<n; i++){
            printf("%d", safeSequence[i]);
        }
    }
    else{
        printf("DEADLOCK condition occured!");
    }
}
