#include <iostream>

using namespace std;

void manual_swap(int& a, int& b) {
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

int partition(int A[], int p, int r) {
    int pivot = A[r];
    int i = p - 1;

    for (int j = p; j < r; ++j) {
        if (A[j] <= pivot) {
            i++;
            manual_swap(A[i], A[j]);
        }
    }
    manual_swap(A[i + 1], A[r]);
    return i + 1;
}

void quickSort(int A[], int p, int r) {
    if (p < r) {
        int q = partition(A, p, r);
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

    int single_arr[] = {42};
    int n_single = 1;
    cout << "\nOriginal single: ";
    printArray(single_arr, n_single);
    quickSort(single_arr, 0, n_single - 1);
    cout << "Sorted single:   ";
    printArray(single_arr, n_single);

    return 0;
}