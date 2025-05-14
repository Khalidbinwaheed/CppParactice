#include <iostream>

using namespace std;

void swaping(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int subarray(int A[], int p, int r) {
    int pivot = A[r];
    int i = p - 1;

    for (int j = p; j < r; ++j) {
        if (A[j] <= pivot) {
            i++;
            swaping(A[i], A[j]);
        }
    }
    swaping(A[i + 1], A[r]);
    return i + 1;
}

void quickSort(int A[], int p, int r) {
    if (p < r) {
        int q = subarray(A, p, r);
        quickSort(A, p, q - 1);
        quickSort(A, q + 1, r);
    }
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);

    cout << "Sorted array:   ";
    printArray(arr, n);

    return 0;
}