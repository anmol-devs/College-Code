#include <iostream>
using namespace std;

// 1. Recursive Function for Factorial
// We use 'long long' because factorials get very big very fast
long long factorial(int n) {
    // Base Case: Factorial of 0 or 1 is 1
    if (n <= 1)
        return 1;
    else
        // Recursive Step: n * factorial of (n-1)
        return n * factorial(n - 1);
}

// 2. Recursive Function for Fibonacci Series
// Returns the nth term in the series
int fibonacci(int n) {
    // Base Case: Fib(0) is 0, Fib(1) is 1
    if (n <= 1)
        return n;
    else
        // Recursive Step: Sum of previous two terms
        return fibonacci(n - 1) + fibonacci(n - 2);
}

// Helper to print the series
void printFibSeries(int n) {
    cout << "Fibonacci Series up to " << n << " terms: ";
    for (int i = 0; i < n; i++) {
        cout << fibonacci(i) << " ";
    }
    cout << endl;
}

int main() {
    int choice, num;

    while (true) {
        cout << "\n--- RECURSION MENU ---";
        cout << "\n1. Factorial";
        cout << "\n2. Fibonacci Series";
        cout << "\n3. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        if (choice == 3) break;

        cout << "Enter a positive number: ";
        cin >> num;

        switch (choice) {
            case 1:
                cout << "Factorial of " << num << " is: " << factorial(num) << endl;
                break;
            case 2:
                printFibSeries(num);
                break;
            default:
                cout << "Invalid Choice!" << endl;
        }
    }
    return 0;
}