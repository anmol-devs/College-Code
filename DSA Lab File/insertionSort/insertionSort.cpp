#include <iostream>
using namespace std;

// Function to perform Insertion Sort
void insertionSort(int arr[], int n) {
    int key, j;

    // Loop through elements starting from index 1
    for (int i = 1; i < n; i++) {
        key = arr[i];   // Take the current element
        j = i - 1;      // Index of previous element

        // Move elements that are greater than key one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert the key into its correct position
        arr[j + 1] = key;
    }
}

// Function to display array elements
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

    // Call insertion sort function
    insertionSort(arr, n);

    cout << "\nArray after Insertion Sort:\n";
    displayArray(arr, n);

    return 0;
}