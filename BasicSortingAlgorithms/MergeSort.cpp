#include<bits/stdc++.h>
using namespace std;

void merge(int *arr, int si, int ei, int mid) { // O(N)
	
	vector<int> temp;

	int i = si;
	int j = mid+1;

	//adds elements in ascending order
	while( i <= mid && j <= ei ) {

		if( arr[i] <= arr[j] ) {
			temp.push_back(arr[i++]);
		} else {
			temp.push_back(arr[j++]);
		}
	
	}

	//adds remaining elements
	while( i <= mid ) {
	
		temp.push_back(arr[i++]);
	
	}

	while( j <= ei ) {
	
		temp.push_back(arr[j++]);
	
	}

	// from temp vector --> original array
	for(int i = si, x=0; i <= ei; i++) {
	
		arr[i] = temp[x++];
	
	}

}

void mergeSort(int *arr, int si, int ei) { // O(log N)

	if( si >= ei ) return;

	int mid = si + (ei - si)/2;

	//left
	mergeSort(arr, si, mid);

	//right
	mergeSort(arr, mid + 1, ei);

	//merging sorted arrays
	merge(arr, si, ei, mid);

}

int main()
{
	  cout << "\n";
    cout << "============================================================\n";
    cout << "||              MERGE SORTING ALGORITHM                   ||\n";
    cout << "============================================================\n\n";

	int n;
	cout << " --> Enter the number of elements you want to enter in Array: ";
	cin >> n;
	
	int arr[n];
	cout << " --> Enter the elements (un-sorted): ";
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	mergeSort(arr, 0, n - 1);

	for(int num : arr ) {

		cout << num << ' ';
	
	}
	
	cout << '\n';
	
	return 0;

}
