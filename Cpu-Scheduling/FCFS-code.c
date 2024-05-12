#include <stdio.h>
#include <stdlib.h>


void bubbleSort(float AT[], int process[], float BT[], int n){
    int i, j;
    int temp_AT, temp_BT, temp_Process;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(AT[j]>AT[j+1]){
                temp_AT = AT[j];
                AT[j] = AT[j+1];
                AT[j+1] = temp_AT;

                temp_Process = process[j];
                process[j] = process[j+1];
                process[j+1] = temp_Process;

                temp_BT = BT[j];
                BT[j] = BT[j+1];
                BT[j+1] = temp_BT;
            }
        }
    }
}


void FCFS(float AT[], int process[], float BT[], int n){
    float a_tat = 0, a_wt = 0;
    float CT[n], TAT[n], WT[n];
    float gantt[n];

    gantt[0] = AT[0];
    for(int i=0; i<n; i++){
        gantt[i] = BT[i-1]+gantt[i-1];
    }
    for(int i=0; i<n; i++){
        CT[i]=gantt[i];
        WT[i]=CT[i]-AT[i];
        TAT[i]=WT[i]+BT[i];
        a_wt+=WT[i];
        a_tat+=TAT[i];
    }
    printf("Pno\tAT\tBT\tCT\tWT\tTAT\n");
    for(int i=0; i<n; i++){
        printf("%d\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\n", i+1, AT[i], BT[i], CT[i], WT[i], TAT[i]);
    }
    printf("\nAverage waiting time: %f", a_wt/n);
    printf("\nAverage turn around time: %f", a_tat/n);

}

int main(){
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    float AT[n], BT[n], process[n];
    for(int i=0; i<n; i++){
        printf("Enter the AT and BT for process[%d]\n", i+1);
        printf("Arrival Time: ");
        scanf("%f", &AT[i]);
        printf("Burst Time: ");
        scanf("%f", &BT[i]);
    }

    bubbleSort(AT,process,BT,n);
    FCFS(AT,process,BT,n);
}

