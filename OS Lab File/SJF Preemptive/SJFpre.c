#include <stdio.h>

int main() {
    int n, i;
    int arrival[20], burst[20], rem[20], completed[20];
    int completion[20], turnaround[20], waiting[20];
    int time = 0, completed_count = 0;

    printf("Enter number of processes (max 20): ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Process %d Arrival time: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Process %d Burst time: ", i + 1);
        scanf("%d", &burst[i]);
        rem[i] = burst[i];
        completed[i] = 0;
    }

    // Start time from earliest arrival
    int earliest = arrival[0];
    for (i = 1; i < n; i++) if (arrival[i] < earliest) earliest = arrival[i];
    time = earliest;

    // simple Gantt tracking (optional)
    int gantt_proc[1000], gantt_time[1000], gidx = 0;

    while (completed_count < n) {
        // find process with minimum remaining time among arrived
        int idx = -1;
        int min_rem = 1e9;
        for (i = 0; i < n; i++) {
            if (!completed[i] && arrival[i] <= time && rem[i] > 0) {
                if (rem[i] < min_rem) {
                    min_rem = rem[i];
                    idx = i;
                } else if (rem[i] == min_rem) {
                    // tie-breaker: earlier arrival
                    if (arrival[i] < arrival[idx]) idx = i;
                }
            }
        }

        if (idx != -1) {
            // record gantt entry when process changes
            if (gidx == 0 || gantt_proc[gidx - 1] != idx) {
                gantt_proc[gidx] = idx;
                gantt_time[gidx] = time;
                gidx++;
            }

            // run for 1 time unit
            rem[idx]--;
            time++;

            if (rem[idx] == 0) {
                completion[idx] = time;
                turnaround[idx] = completion[idx] - arrival[idx];
                waiting[idx] = turnaround[idx] - burst[idx];
                completed[idx] = 1;
                completed_count++;
            }
        } else {
            // idle -> jump to next arrival
            int next_arrival = 1e9;
            for (i = 0; i < n; i++) if (!completed[i] && arrival[i] < next_arrival) next_arrival = arrival[i];
            time = next_arrival;
        }
    }

    // print results
    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    float total_tat = 0, total_wt = 0;
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n", i + 1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
        total_tat += turnaround[i];
        total_wt += waiting[i];
    }
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time    = %.2f\n", total_wt / n);

    // print simple gantt
    printf("\nGantt Chart (process index and start time):\n");
    for (i = 0; i < gidx; i++) printf("| P%d (start %d) ", gantt_proc[i] + 1, gantt_time[i]);
    printf("|\n");
    printf("Timeline: ");
    for (i = 0; i < gidx; i++) printf("%d -> ", gantt_time[i]);
    printf("%d\n", time);

    return 0;
}