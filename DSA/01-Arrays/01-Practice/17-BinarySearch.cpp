#include <iostream>
#include <vector>

using namespace std;
int main() {
    cout<<"Program to find element using binary search."<<endl;
    vector<int> arr = {10, 20, 30, 40, 50};
    int element = 20, found = 0, beg=0, end=arr.size()-1, mid;
    while(beg<=end) {
        mid=beg+(end-beg)/2; //Preventing Integer Overflow in mid Calculation.
        if(arr[mid]==element) {
            cout<<"Element is present.";
            found = 1;
            break;
        } else if (arr[mid]>element) {
            end = mid-1;
        } else if (arr[mid]<element) {
            beg = mid+1;
        } 
    } 
    if(found==0) {
        cout<<"Element is not present in an array";
    }
    return 0;

}