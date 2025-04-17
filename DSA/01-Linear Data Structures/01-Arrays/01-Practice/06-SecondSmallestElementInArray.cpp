#include<iostream>
#include<vector>

using namespace std;
int main() {
    cout<<"Second smallest element in an array."<<endl;
    vector<int> arr = {10, 30, 50, 20, 40};
    int smallest = 99999, secondSmall= 99999;
    for(int i=0; i<=arr.size()-1; i++) {
        if(arr[i]<smallest) { 
            smallest = arr[i];
        } 
        if(arr[i] != smallest) {
            if(arr[i]<secondSmall) {
                secondSmall=arr[i];
            }
        }
    } 
    cout<<"Second smallest element in an array: "<<secondSmall<<endl;
    return 0;
}