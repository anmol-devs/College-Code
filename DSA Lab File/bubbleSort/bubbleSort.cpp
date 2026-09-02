#include <iostream>
using namespace std;
    
// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    int temp;
    bool swapped;  // To check if any swapping happened in a pass

    // Outer loop: runs (n-1) times
    for (int i = 0; i < n - 1; i++) {
        swapped = false;  // reset swapped flag before each pass

        // Inner loop: compares each pair of adjacent elements
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements if they are in the wrong order
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swapped = true;  // mark that swapping happened
            }
        }

        // If no swapping happened, array is already sorted → break early
        if (!swapped) {
            break;
        }
    }
}

// Function to display the array
void displayArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[50], n;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "\nArray before sorting:\n";
    displayArray(arr, n);

    // Call the bubbleSort function
    bubbleSort(arr, n);

    cout << "\nArray after Bubble Sort:\n";
    displayArray(arr, n);

    return 0;
}