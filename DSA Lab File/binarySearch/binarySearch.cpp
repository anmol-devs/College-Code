#include <iostream>
using namespace std;

// Function Definition
// It takes the array, the size of array (n), and the value to search (key)
int binarySearch(int arr[], int n, int key) {
    int start = 0;
    int end = n - 1;
    int mid;

    while (start <= end) {
        mid = (start + end) / 2;

        // Check if key is present at mid
        if (arr[mid] == key) {
            return mid; // Return the index where it was found
        }

        // If key is smaller, ignore right half
        if (key < arr[mid]) {
            end = mid - 1;
        }
        // If key is greater, ignore left half
        else {
            start = mid + 1;
        }
    }

    return -1; // Return -1 means element was NOT found
}

int main() {
    int n, i, key, result;
    int arr[100];

    cout << "Enter number of elements: ";
    cin >> n;

    // Binary search REQUIRES sorted input
    cout << "Enter " << n << " integers in ASCENDING order: \n";
    for (i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value to find: ";
    cin >> key;

    // Calling the function
    result = binarySearch(arr, n, key);

    // Checking the result from the function
    if (result == -1) {
        cout << "Element is not present in array.";
    } else {
        // We add 1 to result because computers start counting at 0, humans at 1
        cout << "Element found at position: " << result + 1;
    }

    return 0;
}   