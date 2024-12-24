#include <bits/stdc++.h>
using namespace std;

//the root is always the greatest 
void MAX_Heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i+1 ;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    if (largest != i) {
        swap(arr[i], arr[largest]);
        MAX_Heapify(arr, n, largest);
    }
}

//insure that all mantain max heap
void Build_Max_Heap(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--)
        MAX_Heapify(arr, n, i);
}

//acually sort the array
void Heap_Sort(int arr[], int n) {
    Build_Max_Heap(arr, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        MAX_Heapify(arr, i, 0);
    }
}

int main() {
    int arr[] = { 9, 4, 3, 8, 10, 2, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    Heap_Sort(arr, n);

   //print the soetes array
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";

    return 0;
}
