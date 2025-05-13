//Problem Link -> https://www.naukri.com/code360/problems/first-and-last-position-of-an-element-in-sorted-array_1082549?source=youtube&campaign=love_babbar_codestudio2&leftPanelTabValue=PROBLEM

int firstOccurance(vector<int>& array, int size, int key) {
    int start=0; 
    int end = size-1; 
    int mid = start + (end-start)/2; 
    int ans =-1; 
    
    while(start<=end) {
        if(array[mid] == key) {
            ans = mid; 
            end = mid-1; //Narrows down its search space to the left subarray by setting end = mid - 1.This ensures that the next iteration of the while loop will only consider elements before the current mid.
        } else if(array[mid]<key) {
            start = mid+1;
        } else if(array[mid]>key) {
            end = mid - 1;
        } 
        mid = start + (end-start)/2; 
    } 
    return ans;
} 

int lastOccurance(vector<int>& array, int size, int key) {
    int start=0; 
    int end = size-1; 
    int mid = start + (end-start)/2; 
    int ans =-1; 
    
    while(start<=end) {
        if(array[mid] == key) {
            ans = mid; 
            start = mid+1; // Focuses its search on the right subarray by setting start = mid + 1. This makes sure the subsequent iterations only look at elements after the current mid.
        } else if(array[mid]<key) {
            start = mid+1;
        } else if(array[mid]>key) {
            end = mid - 1;
        } 
        mid = start + (end-start)/2;  

    } 
    return ans;
} 


pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
{
    // Write your code here 
    pair <int, int>p; 
    p.first = firstOccurance(arr, n, k); 
    p.second = lastOccurance(arr,n, k); 
    return p;

    
}
