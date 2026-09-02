#include<stdio.h>

int main(){
    int n, i, time, count = 0, smallest;
    int at[20], bt[20], priority[20], rt[20];
    int wt[20], ct[20], tat[20];
    float total_wt = 0, total_tat = 0;

    priority[19] = 9999;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter arrival time, Burst time, and Priority for each process:\n");
    for(i = 0;i < n; i++){
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);
        rt[i] = bt[i];
    }

    for(time = 0; count!=n; time++){
        smallest = 19;

        for(i = 0; i < n; i++){
            if(at[i] <= time && rt[i] > 0 && priority[i] < priority[smallest]){
                smallest = i;
            }
        }

        rt[smallest]--;

        if(rt[smallest]==0){
            count++;

            int end_time = time + 1;

            ct[smallest] = end_time;
            tat[smallest] = end_time - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];

            total_tat += tat[smallest];
            total_wt += wt[smallest];
        }
    }

    printf("\nPID\tPriority\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");

    for(i = 0; i < n; i++){
        printf("P%d\t\t%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               i + 1, priority[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnarounf Time: %.2f\n", total_tat / n);


    return 0;

}