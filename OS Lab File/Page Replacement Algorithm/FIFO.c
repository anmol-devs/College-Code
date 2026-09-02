#include <stdio.h>

int main() {
    int i, j, n, frames, page_faults = 0, k = 0;
    int pages[50], temp[10];
    int found; // Flag to check if page exists (Hit or Miss)

    // Step 1: Input Number of Frames (Seats)
    printf("Enter number of Frames: ");
    scanf("%d", &frames);

    // Step 2: Input Page Reference String
    printf("Enter number of Pages: ");
    scanf("%d", &n);

    printf("Enter the Page Reference String (space separated): ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames with -1 (meaning empty)
    for(i = 0; i < frames; i++) {
        temp[i] = -1;
    }

    printf("\nReference String\t|  Frames Status\t|  Hit/Miss\n");

    // --- MAIN FIFO LOGIC ---
    for(i = 0; i < n; i++) {
        
        found = 0; // Reset flag for every new page

        // Check if page is already inside (HIT)
        for(j = 0; j < frames; j++) {
            if(temp[j] == pages[i]) {
                found = 1;
                break; // Found it! No need to replace anyone.
            }
        }

        // If NOT found (MISS / Page Fault)
        if(found == 0) {
            // Replace the oldest page at index 'k'
            temp[k] = pages[i];
            
            // Move pointer to the next oldest (Circular logic)
            // If k reaches the end, it goes back to 0
            k = (k + 1) % frames;
            
            page_faults++;
        }

        // --- PRINTING THE TABLE ROW ---
        printf("%d\t\t\t|  ", pages[i]);
        for(j = 0; j < frames; j++) {
            if(temp[j] != -1)
                printf("%d  ", temp[j]);
            else
                printf("-  "); // Print - for empty slots
        }
        
        // Print Hit or Miss status
        if(found == 1)
            printf("\t\t|  Hit");
        else
            printf("\t\t|  Miss");
            
        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", n - page_faults);

    return 0;
}