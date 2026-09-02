#include <stdio.h>

int main() {
    int n, i, time, count = 0, smallest;
    int at[10], bt[10], priority[10], rt[10];
    int ct[10], tat[10], wt[10]; // Arrays to store Final Results
    float total_wt = 0, total_tat = 0;

    // Is array ko comparison ke liye use karenge (Dummy Max Value)
    priority[9] = 9999; 

    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    printf("Enter Arrival Time, Burst Time, and Priority for each Process:\n");
    // Note: Lower Number = Higher Priority (e.g. 1 is highest)
    for(i = 0; i < n; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d %d %d", &at[i], &bt[i], &priority[i]);
        rt[i] = bt[i]; // Remaining time ko Burst time ke barabar set karo
    }

    // --- MAIN SIMULATION LOOP ---
    // Time 0 se shuru hoga aur tab tak chalega jab tak saare process (count == n) khatam na ho jayein
    for(time = 0; count != n; time++) {
        
        smallest = 9; // Default dummy index

        // Step 1: Find process with Highest Priority (Lowest value)
        // Jo aa chuka ho (at <= time) aur khatam na hua ho (rt > 0)
        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && priority[i] < priority[smallest]) {
                smallest = i;
            }
        }

        // Step 2: Decrease remaining time of winner by 1
        rt[smallest]--;

        // Step 3: Check if process finished
        if(rt[smallest] == 0) {
            count++; // Ek process khatam
            
            // Completion Time calculation
            int end_time = time + 1;
            
            // Result ko Arrays mein store kar lo (Print mat karo abhi)
            ct[smallest] = end_time;
            tat[smallest] = end_time - at[smallest];
            wt[smallest] = tat[smallest] - bt[smallest];

            total_wt += wt[smallest];
            total_tat += tat[smallest];
        }
    }

    // --- STEP 4: DISPLAY TABLE (FCFS Style) ---
    printf("PID\tPriority\tArrival\tBurst\tCompletion\tTurnAround\tWaiting\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t%d\t%d\t\t%d\t\t%d\n", 
               i + 1, priority[i], at[i], bt[i], ct[i], tat[i], wt[i]);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);

    return 0;
}