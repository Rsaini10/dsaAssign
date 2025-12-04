#include <iostream>
using namespace std;

int main() {
    int n;
    cout<<"Enter number of elements: ";
    cin>>n;

    int arr[n];
    cout<<"Enter sorted array elements (with one missing): ";
    for (int i=0;i<n;i++) {
        cin>>arr[i];
    }
    int low=arr[0];
    int high=arr[n - 1];
    int sum1 = (high * (high + 1)) / 2 - (low * (low - 1)) / 2;

    int actual_sum=0;
    for (int i=0; i<n;i++) {
        actual_sum+=arr[i];
    }
    int missing=sum1-actual_sum;
    cout <<"Missing number is: "<<missing<<endl;
    return 0;
}