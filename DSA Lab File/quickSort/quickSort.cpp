#include <iostream>
using namespace std;

// Helper function to swap two numbers
void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

// 1. Partition Function (The Heavy Lifter)
// It places the pivot in the correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // We choose the last element as the pivot
    int i = (low - 1);     // i tracks the position of the "smaller" elements

    for (int j = low; j < high; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            i++; // Move the "smaller" boundary forward
            swap(arr[i], arr[j]); // Swap them
        }
    }
    // Finally, place the pivot in the correct spot (after the last smaller element)
    swap(arr[i + 1], arr[high]);
    return (i + 1); // Return the index where the pivot is now sitting
}

// 2. QuickSort Function (The Manager)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // Find the partition index (pi)
        // After this step, arr[pi] is in the correct sorted place
        int pi = partition(arr, low, high);

        // Recursively sort the elements BEFORE the partition
        quickSort(arr, low, pi - 1);

        // Recursively sort the elements AFTER the partition
        quickSort(arr, pi + 1, high);
    }
}

// 3. Helper to print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int n;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter " << n << " integers: \n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original Array: ";
    printArray(arr, n);

    // Calling the function
    quickSort(arr, 0, n - 1);

    cout << "Sorted Array:   ";
    printArray(arr, n);

    return 0;
}