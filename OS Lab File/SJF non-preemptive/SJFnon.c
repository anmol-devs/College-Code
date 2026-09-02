#include <stdio.h>

int main() {
    int n, i, j;
    int arrival[20], burst[20], completed[20];
    int waiting[20], turnaround[20], completion[20];
    int time = 0, completed_count = 0;

    printf("Enter number of processes (max 20): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Process %d Arrival time: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Process %d Burst time: ", i + 1);
        scanf("%d", &burst[i]);
        completed[i] = 0; // not completed
    }

    // Start time from earliest arrival
    int earliest = arrival[0];
    for (i = 1; i < n; i++) if (arrival[i] < earliest) earliest = arrival[i];
    time = earliest;

    while (completed_count < n) {
        // find index of shortest job among arrived & not completed
        int idx = -1;
        int min_burst = 1e9;
        for (i = 0; i < n; i++) {
            if (!completed[i] && arrival[i] <= time) {
                if (burst[i] < min_burst) {
                    min_burst = burst[i];
                    idx = i;
                } else if (burst[i] == min_burst) {
                    // tie-breaker: earlier arrival or lower index
                    if (arrival[i] < arrival[idx]) idx = i;
                }
            }
        }

        if (idx != -1) {
            // run this process to completion
            time += burst[idx];
            completion[idx] = time;
            turnaround[idx] = completion[idx] - arrival[idx];
            waiting[idx] = turnaround[idx] - burst[idx];
            completed[idx] = 1;
            completed_count++;
        } else {
            // no process available yet -> idle time jump to next arrival
            int next_arrival = 1e9;
            for (i = 0; i < n; i++) if (!completed[i] && arrival[i] < next_arrival) next_arrival = arrival[i];
            time = next_arrival; // jump time forward (avoids step-by-step idle)
        }
    }

    // Print results and averages
    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    float total_tat = 0, total_wt = 0;
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", i + 1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
        total_tat += turnaround[i];
        total_wt += waiting[i];
    }
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time    = %.2f\n", total_wt / n);

    return 0;
}