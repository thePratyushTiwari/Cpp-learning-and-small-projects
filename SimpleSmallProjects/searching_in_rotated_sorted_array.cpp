#include<bits/stdc++.h>
using namespace std;

/*
	IMPLEMENTING BINARY SEARCH IN ROTATED SORTED ARRAY
*/

int rotatedBinarySearch(int *arr, int si, int ei, int target) {

	if( si > ei ) return -1;

	int mid = si + (ei - si)/2;
	if(arr[mid] == target) return mid;

	else if( arr[si] <= arr[mid] ) {
		if(arr[si] <= target && target <= arr[mid] )
			return rotatedBinarySearch(arr, si, mid - 1, target);
		else
			return rotatedBinarySearch(arr, mid + 1, ei, target);
	}
	else {
		if(arr[mid] <= target && target <= arr[ei])
			return rotatedBinarySearch(arr, mid + 1, ei, target);
		else
			return rotatedBinarySearch(arr, si, mid - 1, target);
	}
}

int main()
{
	int size; cin >> size;
	int arr[size];
	for(int i = 0; i < size; i++) {
		cin >> arr[i];
	}

	int target;
	cout << "Enter target value: "; cin >> target;

	cout << rotatedBinarySearch(arr, 0, size - 1, target) << '\n';
	return 0;
}
