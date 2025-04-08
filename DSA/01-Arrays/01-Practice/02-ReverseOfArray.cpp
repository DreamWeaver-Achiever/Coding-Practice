#include<iostream>
#include<vector>
using namespace std;

int main() {
    vector<int> arr = {10, 20, 30, 40, 50};
    cout<<"Reverse of an array: ";
    for(int i=arr.size()-1; i>=0; i--) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;

}