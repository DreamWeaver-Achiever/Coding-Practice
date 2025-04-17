#include <iostream>
#include <vector>
using namespace std;
int main() {
    cout<<"Swap Maximum And Minimum Elements In An Array \n";
    vector<int> arr = {10, 30, 50, 20, 40};
    int smallest = 99999, largest=-99999, pos1=-1, pos2=-1;
    for(int i=0; i<=arr.size()-1; i++) {
        if(arr[i]>largest) {
            largest = arr[i];
            pos2=i;
        }
        if(arr[i]<smallest) {
            smallest=arr[i];
            pos1=i;
        }
    } 
    cout<<"\nLargest: "<<largest<<" Smallest: "<<smallest;

   arr[pos1]=largest;
   arr[pos2]=smallest;
    cout<<"\nArray after swapping largest and smallest elements in it: ";
    for(int i=0; i<=arr.size()-1; i++) {
        cout<<arr[i]<<" ";
    } 
    return 0;
}