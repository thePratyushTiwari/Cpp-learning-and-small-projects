#include<iostream>
#include<vector>
using namespace std;

void heapify(int i, vector<int>& arr, int n) {
    int left = i*2 + 1;
    int right = i*2 + 2;
    int maxI = i;

    if(left < n && arr[left] > arr[maxI]) maxI = left;
    if(right < n && arr[right] > arr[maxI]) maxI = right;

    if(maxI != i) {
        swap(arr[maxI], arr[i]);
        heapify(maxI, arr, n);
    }
}

void heapSort(vector<int>& heap) {
    int n = heap.size();

    for(int i = n/2 - 1; i >= 0; i--) {
        heapify(i, heap, n);
    }

    for(int i = n - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);
        heapify(0, heap, i);
    }
}

int main()
{
    int n;
    cout << "How many elements you want to enter in the heap: ";
    cin >> n;

    vector<int> heap(n);

    cout << "Enter " << n << " elements: ";
    for(int i=0; i<n; i++) {
        cin >> heap[i];
    }

    heapSort(heap);

    cout << "-----------------------------\nSorted heap:  ";
    for(int i=0; i<n; i++) {
        cout << heap[i] << ' ';
    }
    cout << '\n';
    return 0;
}
