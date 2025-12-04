#include <iostream>
using namespace std;

void heapify(int arr[], int n, int i, bool ascending) {
    int extreme = i;  
    int left = 2 * i + 1;  
    int right = 2 * i + 2; 

    if (ascending) {
        if (left < n && arr[left] > arr[extreme])
            extreme = left;
        if (right < n && arr[right] > arr[extreme])
            extreme = right;
    } else {
        if (left < n && arr[left] < arr[extreme])
            extreme = left;
        if (right < n && arr[right] < arr[extreme])
            extreme = right;
    }

    if (extreme != i) {
        swap(arr[i], arr[extreme]);
        heapify(arr, n, extreme, ascending);
    }
}

void heapSort(int arr[], int n, bool ascending) {
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i, ascending);

    for (int i = n - 1; i >= 0; i--) {
        swap(arr[0], arr[i]);
        heapify(arr, i, 0, ascending);
    }
}

int main() {
    int arr[] = {12, 3, 19, 4, 8, 7, 15};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Original array: ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;

    heapSort(arr, n, true);
    cout << "Sorted (Increasing): ";
    for(int i=0;i<n;i++) cout << arr[i] << " ";
    cout << endl;

    int arr2[] = {12, 3, 19, 4, 8, 7, 15};
    heapSort(arr2, n, false);
    cout << "Sorted (Decreasing): ";
    for(int i=0;i<n;i++) cout << arr2[i] << " ";
    cout << endl;

    return 0;
}
