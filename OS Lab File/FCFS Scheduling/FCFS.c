#include <stdio.h>

int main() {
    int n, i;
    int burst_time[20], waiting_time[20], turnaround_time[20];
    float avg_waiting_time = 0, avg_turnaround_time = 0;

    // Step 1: Input number of processes
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Step 2: Input burst time for each process
    printf("Enter the burst time for each process:\n");
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &burst_time[i]);
    }

    // Step 3: Calculate Waiting Time
    // Pehle process ko wait nahi karna padta (kyunki wo sabse pehle aaya)
    waiting_time[0] = 0; 

    for(i = 1; i < n; i++) {
        // Current process ka wait = Pichle process ka wait + Pichle process ka kaam (Burst)
        waiting_time[i] = burst_time[i-1] + waiting_time[i-1];
    }

    // Step 4: Calculate Turnaround Time & Averages
    for(i = 0; i < n; i++) {
        // Turnaround Time = Khud ka kaam (Burst) + Wait kiya hua time
        turnaround_time[i] = burst_time[i] + waiting_time[i];

        avg_waiting_time += waiting_time[i];
        avg_turnaround_time += turnaround_time[i];
    }

    avg_waiting_time /= n;
    avg_turnaround_time /= n;

    // Step 5: Display results
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t%d\n", i + 1, burst_time[i], waiting_time[i], turnaround_time[i]);
    }

    printf("\nAverage Waiting Time: %.2f", avg_waiting_time);
    printf("\nAverage Turnaround Time: %.2f\n", avg_turnaround_time);

    return 0;
}