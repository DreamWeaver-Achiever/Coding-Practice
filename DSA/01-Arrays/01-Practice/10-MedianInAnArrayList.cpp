#include<iostream>
#include<vector>
using namespace std; 
int main() {
    cout<<"Calculate Median In Array"<<endl;
    vector<int>arr={12, 34, 56, 78};
    int length = arr.size();
    if(length%2 != 0) {
        cout<<"Median: "<<arr[length/2];
    } else {
        cout<<"Median: "<<(arr[length/2]+arr[(length/2)-1])/2;
    }
    return 0;
}