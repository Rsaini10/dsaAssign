#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int start = 0, end = n - 1;

    while (start < end) {
        int minIndex = start;
        int maxIndex = end;

        if (a[minIndex] > a[maxIndex])
            swap(a[minIndex], a[maxIndex]);

        for (int i = start + 1; i < end; i++) {
            if (a[i] < a[minIndex])
                minIndex = i;
            else if (a[i] > a[maxIndex])
                maxIndex = i;
        }

        swap(a[start], a[minIndex]);
        swap(a[end], a[maxIndex]);

        start++;
        end--;
    }
}

int main() {
    int n, a[100];
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
        cin >> a[i];

    improvedSelectionSort(a, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}
