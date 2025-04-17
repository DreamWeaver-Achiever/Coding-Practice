#include <iostream>
#include <vector>

using namespace std;
int main() {
    cout<<"Program to delete element from given position in an array."<<endl;
     vector<int> arr = {10, 20, 30, 40, 50};
     int position = 2;
     for(int i=position; i<=arr.size(); i++) {
        arr[i]=arr[i+1];
     }
     cout<<"Modified array: ";
     for(int i=0; i<arr.size()-1; i++) {
        cout<<arr[i]<<" ";
     }
     return 0;
}