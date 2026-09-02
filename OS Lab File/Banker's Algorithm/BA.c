#include <stdio.h>

#define MAXP 10
#define MAXR 10

int is_safe(int n, int m, int Allocation[MAXP][MAXR], int Need[MAXP][MAXR], int Available[MAXR], int safe_seq[MAXP]);

int main() {
    int n, m;
    int i, j;

    printf("=== Banker's Algorithm (Deadlock Avoidance) ===\n\n");

    printf("Enter number of processes (n) and number of resource types (m):\n");
    printf("Format: n m  (e.g. 5 3)\n");
    if (scanf("%d %d", &n, &m) != 2) return 0;

    int Allocation[MAXP][MAXR];
    int Max[MAXP][MAXR];
    int Need[MAXP][MAXR];
    int Available[MAXR];
    int safe_seq[MAXP];

    printf("\nEnter Allocation matrix (n rows; each row has m integers):\n");
    printf("Row format example (for P0): a0 a1 a2 ...\n");
    for (i = 0; i < n; i++) {
        printf("Allocation P%d : ", i);
        for (j = 0; j < m; j++) scanf("%d", &Allocation[i][j]);
    }

    printf("\nEnter Max matrix (n rows; each row has m integers):\n");
    for (i = 0; i < n; i++) {
        printf("Max P%d        : ", i);
        for (j = 0; j < m; j++) scanf("%d", &Max[i][j]);
    }

    printf("\nEnter Available vector (m integers):\n");
    printf("Available : ");
    for (j = 0; j < m; j++) scanf("%d", &Available[j]);

    // Calculate Need = Max - Allocation
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            Need[i][j] = Max[i][j] - Allocation[i][j];
            if (Need[i][j] < 0) Need[i][j] = 0; // safety
        }
    }

    // Print matrices neatly
    printf("\n--- Allocation Matrix ---\n\t");
    for (j = 0; j < m; j++) printf("R%d\t", j);
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (j = 0; j < m; j++) printf("%d\t", Allocation[i][j]);
        printf("\n");
    }

    printf("\n--- Max Matrix ---\n\t");
    for (j = 0; j < m; j++) printf("R%d\t", j);
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (j = 0; j < m; j++) printf("%d\t", Max[i][j]);
        printf("\n");
    }

    printf("\n--- Need Matrix (Max - Allocation) ---\n\t");
    for (j = 0; j < m; j++) printf("R%d\t", j);
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (j = 0; j < m; j++) printf("%d\t", Need[i][j]);
        printf("\n");
    }

    printf("\nAvailable: ");
    for (j = 0; j < m; j++) printf("%d ", Available[j]);
    printf("\n");

    // Check safety
    int safe = is_safe(n, m, Allocation, Need, Available, safe_seq);
    if (safe) {
        printf("\nResult: System is in a SAFE state.\nSafe sequence: ");
        for (i = 0; i < n; i++) {
            if (i) printf(" -> ");
            printf("P%d", safe_seq[i]);
        }
        printf("\n");
    } else {
        printf("\nResult: System is NOT in a safe state (UNSAFE).\n");
    }

    // Optional: test a request
    char choice;
    printf("\nDo you want to test a request from a process? (y/n): ");
    scanf(" %c", &choice);
    if (choice == 'y' || choice == 'Y') {
        int pid;
        printf("Enter process id making the request (0 to %d): ", n - 1);
        scanf("%d", &pid);
        if (pid < 0 || pid >= n) {
            printf("Invalid process id.\n");
            return 0;
        }

        int Request[MAXR];
        printf("Enter request vector (m integers): ");
        for (j = 0; j < m; j++) scanf("%d", &Request[j]);

        // Request <= Need?
        int ok = 1;
        for (j = 0; j < m; j++) if (Request[j] > Need[pid][j]) ok = 0;
        if (!ok) {
            printf("Request exceeds process's declared maximum need. DENIED.\n");
        } else {
            ok = 1;
            for (j = 0; j < m; j++) if (Request[j] > Available[j]) ok = 0;
            if (!ok) {
                printf("Resources not available right now. Process must wait.\n");
            } else {
                // Try temporary allocation
                int Av_copy[MAXR], Alloc_copy[MAXP][MAXR], Need_copy[MAXP][MAXR];
                for (j = 0; j < m; j++) Av_copy[j] = Available[j];
                for (i = 0; i < n; i++)
                    for (j = 0; j < m; j++) {
                        Alloc_copy[i][j] = Allocation[i][j];
                        Need_copy[i][j] = Need[i][j];
                    }

                for (j = 0; j < m; j++) {
                    Available[j] -= Request[j];
                    Allocation[pid][j] += Request[j];
                    Need[pid][j] -= Request[j];
                }

                int safe_after = is_safe(n, m, Allocation, Need, Available, safe_seq);
                if (safe_after) {
                    printf("Request can be GRANTED. System remains SAFE.\nNew safe sequence: ");
                    for (i = 0; i < n; i++) {
                        if (i) printf(" -> ");
                        printf("P%d", safe_seq[i]);
                    }
                    printf("\n");
                } else {
                    printf("Granting request would make system UNSAFE. Request DENIED.\n");
                    // Rollback
                    for (j = 0; j < m; j++) Available[j] = Av_copy[j];
                    for (i = 0; i < n; i++)
                        for (j = 0; j < m; j++) {
                            Allocation[i][j] = Alloc_copy[i][j];
                            Need[i][j] = Need_copy[i][j];
                        }
                }
            }
        }
    }

    printf("\nProgram finished.\n");
    return 0;
}

int is_safe(int n, int m, int Allocation[MAXP][MAXR], int Need[MAXP][MAXR], int Available[MAXR], int safe_seq[MAXP]) {
    int Work[MAXR];
    int Finish[MAXP];
    int i, j, count = 0, progress;

    for (j = 0; j < m; j++) Work[j] = Available[j];
    for (i = 0; i < n; i++) Finish[i] = 0;

    do {
        progress = 0;
        for (i = 0; i < n; i++) {
            if (!Finish[i]) {
                int canFinish = 1;
                for (j = 0; j < m; j++) {
                    if (Need[i][j] > Work[j]) { canFinish = 0; break; }
                }
                if (canFinish) {
                    for (j = 0; j < m; j++) Work[j] += Allocation[i][j];
                    Finish[i] = 1;
                    safe_seq[count++] = i;
                    progress = 1;
                }
            }
        }
    } while (progress);

    return (count == n);
}
