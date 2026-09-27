#include<bits/stdc++.h>
using namespace std;

int partition(int *arr, int si, int ei ) {
	int i = si - 1;
	int pivot = arr[ei];

	for( int j = si; j < ei; j++ ) {
		if( arr[j] <= pivot ) {
			i++;
			swap(arr[i], arr[j]);
		}
	}

	i++;
	swap(arr[i], arr[ei]);

	return i; //this is the pivot index
}

void quickSort( int *arr, int si, int ei ) {
	
	if( si >= ei ) return;

	int pivotIdx = partition(arr, si, ei);

	quickSort(arr, si, pivotIdx - 1); // left-half
	quickSort(arr, pivotIdx + 1, ei); //right-half

}

void printArr( int *arr, int n ) {
	for( int i = 0; i < n; i++ ) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

int main()
{
	cout << "\n";
  cout << "============================================================\n";
  cout << "||              QUICK SORTING ALGORITHM                   ||\n";
  cout << "============================================================\n\n";

	int n;
	cout << " --> Enter the number of elements you want to enter in Array: ";
	cin >> n;
	
	int arr[n];
	cout << " --> Enter the elements (un-sorted): ";
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	quickSort(arr, 0, n - 1);

	printArr(arr, n);
	
	return 0;

}
