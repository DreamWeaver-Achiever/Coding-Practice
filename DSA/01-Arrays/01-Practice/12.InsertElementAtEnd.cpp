#include <iostream>
#include <vector>
using namespace std;
int main() {
    cout<<"Insert element at the end of an array: "<<endl;
    vector<int> arr = {10, 20, 30, 40};
    int element = 50;
    arr.push_back(element);
    cout<<"Modified array: ";
    for(int i=0; i<arr.size(); i++) {
        cout<<arr[i]<<" ";
    } 
    return 0;
    
}