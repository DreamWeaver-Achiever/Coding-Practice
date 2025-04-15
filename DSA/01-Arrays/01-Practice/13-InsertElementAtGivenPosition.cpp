#include <iostream>
#include <vector>

using namespace std;
int main() {
    cout<<"Insert element at given location in an array"<<endl;
    vector<int> arr = {10, 20, 40, 50};
    int element = 30, position = 2;
    for(int i=arr.size(); i>=position; i--) {
        arr[i] = arr[i-1];
    }
    arr[position] = element;
    for(int i=0; i<=arr.size(); i++) {
        cout<<arr[i]<<" ";
    }
    return 0;
}