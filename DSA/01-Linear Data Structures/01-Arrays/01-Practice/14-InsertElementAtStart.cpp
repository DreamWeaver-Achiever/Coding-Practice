#include <iostream>
#include <vector>

using namespace std;
int main() {
    cout<<"Program to insert element at the begining of an array."<<endl;
    vector<int>arr = {20, 30, 40, 50};
    int element = 10;
    for(int i=arr.size(); i>=0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0]=element;
    cout<<"Modified array: ";
    for(int i=0; i<=arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}