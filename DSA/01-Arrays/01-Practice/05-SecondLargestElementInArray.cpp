#include <iostream>
#include <vector>
using namespace std;
int main() {
    cout<<"Second Largest Element Of An Array.\n";
    vector<int> arr = {10, 30, 50, 20, 40};
    int largest=-99999, secondLarge=-99999;
    for(int i=0; i<=arr.size()-1; i++) {
        if(arr[i]>largest) {
            largest = arr[i];
        } 
        if(arr[i] != largest) {
            if(arr[i]>secondLarge) { 
                secondLarge = arr[i];
            }
        }
    } 
    cout<<"\nSecond Largest Element In An Array: "<<secondLarge<<endl;
    return 0;
}