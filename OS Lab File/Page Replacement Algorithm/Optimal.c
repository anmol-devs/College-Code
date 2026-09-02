#include <stdio.h>

// Helper Function: Predicts which page to replace
// It looks ahead in the future to find the page that will not be used for longest time
int predict(int pages[], int frames_arr[], int n, int index, int frames) {
    int res = -1, farthest = index;
    int i, j;

    for (i = 0; i < frames; i++) {
        int j;
        // Search for frames_arr[i] in the future (from index onwards)
        for (j = index; j < n; j++) {
            if (frames_arr[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        
        // If a page is never used again in future, replace it immediately
        if (j == n)
            return i;
    }

    // If all pages are used in future, replace the one that appears last (farthest)
    return (res == -1) ? 0 : res;
}

int main() {
    int i, j, n, frames, page_faults = 0;
    int pages[50], frames_arr[10];
    int found, pos;

    // Step 1: Input Frames and Pages
    printf("Enter number of Frames: ");
    scanf("%d", &frames);

    printf("Enter number of Pages: ");
    scanf("%d", &n);

    printf("Enter Reference String: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames with -1 (Empty)
    for(i = 0; i < frames; i++) {
        frames_arr[i] = -1;
    }

    printf("\nRef String\t|  Frames Status\t|  Hit/Miss\n");

    // --- MAIN OPTIMAL LOGIC ---
    for(i = 0; i < n; i++) {
        found = 0;

        // 1. CHECK HIT
        for(j = 0; j < frames; j++) {
            if(frames_arr[j] == pages[i]) {
                found = 1;
                break;
            }
        }

        // 2. IF MISS (PAGE FAULT)
        if(found == 0) {
            // First check if there is any empty slot (-1)
            int empty_slot = 0;
            for(j = 0; j < frames; j++) {
                if(frames_arr[j] == -1) {
                    frames_arr[j] = pages[i];
                    page_faults++;
                    found = 2; // Special flag to say "Inserted in empty slot"
                    empty_slot = 1;
                    break;
                }
            }

            // If no empty slot, perform Replacement
            if(empty_slot == 0) {
                // Find the victim page using future prediction
                pos = predict(pages, frames_arr, n, i + 1, frames);
                
                frames_arr[pos] = pages[i];
                page_faults++;
            }
        }

        // --- PRINT ROW ---
        printf("%d\t\t\t|  ", pages[i]);
        for(j = 0; j < frames; j++) {
            if(frames_arr[j] != -1)
                printf("%d  ", frames_arr[j]);
            else
                printf("-  ");
        }

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