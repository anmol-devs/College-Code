#include <stdio.h>

int main() {
    int n, i;
    int arrival[20], burst[20], rem[20];
    int completion[20], turnaround[20], waiting[20];
    int in_queue[20] = {0}, completed[20] = {0};

    // Simple queue for RR (circular)
    int queue[1000], front = 0, rear = 0;
    #define ENQUEUE(x) (queue[rear++] = (x))
    #define DEQUEUE() (queue[front++])
    #define QUEUE_EMPTY (front == rear)

    int time = 0;
    int earliest;

    printf("Enter number of processes (max 20): ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Process %d Arrival time: ", i + 1);
        scanf("%d", &arrival[i]);
        printf("Process %d Burst time: ", i + 1);
        scanf("%d", &burst[i]);
        rem[i] = burst[i];
    }

    printf("Enter Time Quantum: ");
    int quantum;
    scanf("%d", &quantum);
    if (quantum <= 0) quantum = 1; // guard

    // Start time = earliest arrival
    earliest = arrival[0];
    for (i = 1; i < n; i++) if (arrival[i] < earliest) earliest = arrival[i];
    time = earliest;

    // Enqueue all processes that arrive at 'time'
    for (i = 0; i < n; i++) {
        if (arrival[i] <= time && !in_queue[i] && !completed[i]) {
            ENQUEUE(i);
            in_queue[i] = 1;
        }
    }

    // Gantt tracking
    int gantt_proc[2000], gantt_time[2000], gidx = 0;

    int finished_count = 0;
    while (finished_count < n) {

        if (QUEUE_EMPTY) {
            // No ready process now -> jump to next arrival
            int next_arr = 1e9, next_idx = -1;
            for (i = 0; i < n; i++) if (!completed[i] && arrival[i] < next_arr) {
                next_arr = arrival[i];
                next_idx = i;
            }
            time = next_arr;
            // Enqueue processes that arrive now
            for (i = 0; i < n; i++) {
                if (arrival[i] <= time && !in_queue[i] && !completed[i]) {
                    ENQUEUE(i);
                    in_queue[i] = 1;
                }
            }
            continue;
        }

        // Get next process from queue
        int idx = DEQUEUE();
        in_queue[idx] = 0; // temporarily removed from queue

        // Record Gantt slot when process starts
        if (gidx == 0 || gantt_proc[gidx - 1] != idx) {
            gantt_proc[gidx] = idx;
            gantt_time[gidx] = time;
            gidx++;
        }

        // Execute for min(quantum, remaining)
        int exec = (rem[idx] < quantum) ? rem[idx] : quantum;
        int old_time = time;
        time += exec;
        rem[idx] -= exec;

        // During [old_time, time], enqueue newly arrived processes
        for (i = 0; i < n; i++) {
            if (!completed[i] && !in_queue[i] && i != idx && arrival[i] > old_time && arrival[i] <= time) {
                ENQUEUE(i);
                in_queue[i] = 1;
            }
        }

        if (rem[idx] == 0) {
            // Process finished
            completion[idx] = time;
            turnaround[idx] = completion[idx] - arrival[idx];
            waiting[idx] = turnaround[idx] - burst[idx];
            completed[idx] = 1;
            finished_count++;
        } else {
            // Not finished: re-enqueue at tail
            ENQUEUE(idx);
            in_queue[idx] = 1;
        }
    }

    // Print results
    printf("\nProcess\tArrival\tBurst\tCompletion\tTurnaround\tWaiting\n");
    float total_tat = 0, total_wt = 0;
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t\t%d\t\t%d\n",
               i + 1, arrival[i], burst[i], completion[i], turnaround[i], waiting[i]);
        total_tat += turnaround[i];
        total_wt += waiting[i];
    }
    printf("\nAverage Turnaround Time = %.2f\n", total_tat / n);
    printf("Average Waiting Time    = %.2f\n", total_wt / n);

    // Print simple Gantt timeline
    printf("\nGantt Chart (Process number and start time):\n");
    for (i = 0; i < gidx; i++) {
        printf("| P%d (start %d) ", gantt_proc[i] + 1, gantt_time[i]);
    }
    printf("|\nTimeline: ");
    for (i = 0; i < gidx; i++) printf("%d -> ", gantt_time[i]);
    printf("%d\n", time);

    return 0;
}