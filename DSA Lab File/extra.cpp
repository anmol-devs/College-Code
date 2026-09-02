#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int key){
    int start = 0;
    int end = n-1;
    int mid;

    while (start<=end){
        mid = (start + end)/2;
        if (arr[mid]==key) {
            return mid;
        }

        if (arr[mid]>key){
            end = mid -1;
        }

        else {
            start = mid + 1;
        }
    }

    return -1;
}

int main(){
    int arr[30], n, key;
    int result;

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter the elements: ";
    for (int i = 0; i<n; i++) {
        cin >> arr[i];
    }

    cout << "Enter value to find: ";
    cin >> key;

    result = binarySearch(arr, n, key);

    if(result==-1){
        cout << "Element is not present: ";
    } else {
        cout << "Element found at position: " << result + 1;
    }

    return 0;
}