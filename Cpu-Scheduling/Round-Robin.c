#include <stdio.h>

void main(){
    int i, sum = 0, count = 0, NOP, wt = 0, tat = 0, y, quant, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    printf("Enter the number of total processes: ");
    scanf("%d", &NOP);
    y = NOP;

    for(i=0; i<NOP; i++){
        printf("Enter the arrival time and burst time for Process[%d]\n", i+1);
        printf("Arrival time is: ");
        scanf("%d",&at[i]);
        printf("Burst time is: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quant);

    printf("P\tBurstTime\tTAT\tWT\n");
    for(sum=0, i=0; y!=0;){
        if(temp[i]<=quant && temp[i]>0){
            sum = sum + temp[i];
            temp[i]=0;
            count=1;
        }
        else if(temp[i]>0){
            temp[i]=temp[i]-quant;
            sum+=quant;
        }
        if(temp[i]==0 && count==1){
            y--;
            printf("\nProcess No[%d] \t\t %d\t\t\t\t %d\t\t\t %d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt+sum-at[i]-bt[i];
            tat = tat+sum-at[i];
            count=0;
        }
        if(i==NOP-1){
            i=0;
        }
        else if(at[i]<=sum){
            i++;
        }
        else{
            i=0;
        }
    }
    avg_tat = (float)tat/NOP;
    avg_wt = (float)wt/NOP;
    printf("\nAverage Turn around time: %f\n", avg_tat);
    printf("Average waiting time: %f\n", avg_wt);
}

