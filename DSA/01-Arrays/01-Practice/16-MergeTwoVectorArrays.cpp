#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main() {
    cout<<"Program to merge two vector arrays one after another."<<endl;
    vector<int>arr1 = {10, 20};
    vector<int> arr2 = {30, 40, 50};

    arr1.insert(arr1.end(), arr2.begin(), arr2.end());
   for(int i=0; i<arr1.size(); i++) {
    cout<<arr1[i]<<" ";
   }
    return 0;
}