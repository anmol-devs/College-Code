#include <stdio.h>

// Helper function to find the index of the Least Recently Used page
int findLRU(int time[], int n) {
    int i, minimum = time[0], pos = 0;
    
    for(i = 1; i < n; i++) {
        // Jiska time sabse kam hai (yani bahut pehle use hua tha)
        if(time[i] < minimum) {
            minimum = time[i];
            pos = i;
        }
    }
    return pos;
}

int main() {
    int i, j, n, frames, page_faults = 0, counter = 0;
    int pages[50], frames_arr[10], time[10];
    int flag1, flag2, pos;

    // Step 1: Input Frames and Pages
    printf("Enter number of Frames: ");
    scanf("%d", &frames);

    printf("Enter number of Pages: ");
    scanf("%d", &n);

    printf("Enter Reference String: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &pages[i]);
    }

    // Initialize frames array with -1 (Empty)
    for(i = 0; i < frames; i++) {
        frames_arr[i] = -1;
    }

    printf("\nRef String\t|  Frames Status\t|  Hit/Miss\n");

    // --- MAIN LRU LOGIC ---
    for(i = 0; i < n; i++) {
        flag1 = 0; // Hit Check
        flag2 = 0; // Empty Slot Check

        // 1. CHECK HIT: Kya page pehle se frames mein hai?
        for(j = 0; j < frames; j++) {
            if(frames_arr[j] == pages[i]) {
                counter++;
                time[j] = counter; // Time update kar do (Abhi use hua hai)
                flag1 = 1;
                flag2 = 1;
                break;
            }
        }

        // 2. CHECK EMPTY SLOT: Agar Hit nahi hua, toh kya koi khali jagah hai?
        if(flag1 == 0) {
            for(j = 0; j < frames; j++) {
                if(frames_arr[j] == -1) {
                    counter++;
                    page_faults++;
                    frames_arr[j] = pages[i];
                    time[j] = counter;
                    flag2 = 1;
                    break;
                }
            }
        }

        // 3. REPLACE LRU: Agar Hit bhi nahi hua aur jagah bhi nahi hai
        if(flag2 == 0) {
            // Find position of Least Recently Used page
            pos = findLRU(time, frames);
            
            counter++;
            page_faults++;
            frames_arr[pos] = pages[i];
            time[pos] = counter;
        }

        // --- PRINT ROW ---
        printf("%d\t\t\t|  ", pages[i]);
        for(j = 0; j < frames; j++) {
            if(frames_arr[j] != -1)
                printf("%d  ", frames_arr[j]);
            else
                printf("-  ");
        }

        if(flag1 == 1)
            printf("\t\t|  Hit");
        else
            printf("\t\t|  Miss");
        
        printf("\n");
    }

    printf("Total Page Faults: %d\n", page_faults);
    printf("Total Page Hits: %d\n", n - page_faults);

    return 0;
}