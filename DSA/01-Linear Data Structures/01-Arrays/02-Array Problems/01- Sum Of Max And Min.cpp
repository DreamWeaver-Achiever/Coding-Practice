//Problem Statement: https://www.naukri.com/code360/problems/sum-of-max-and-min_1081476?topList=love-babbar-dsa-sheet-problems&problemListRedirection=true&practice_topic%5B%5D=Arrays&attempt_status=COMPLETED&leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
int sumOfMaxMin(int arr[], int n){
	// Write your code here.
	int smallest = INT_MAX, largest = INT_MIN;
	for(int i=0; i<n; i++) {
		if(arr[i]>largest) {
			largest = arr[i];

		} 
		if(arr[i]<smallest) {
			smallest = arr[i];
		}
	} 
	return smallest+largest;
}