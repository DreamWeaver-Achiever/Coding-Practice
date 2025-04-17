#include <iostream>

using namespace std;

int main() {
    cout<<"Read And Display Elements Of An Array: ";
    int n, arr[1000000];
    cout<<"\nEnter size of an array: "; cin>>n;
    cout<<"\nEnter elements of an array: ";
    for(int i=0; i<=n-1; i++) {
        cin>>arr[i];
    }
    cout<<"\nElements of an array entered by an user: ";
    for(int i=0; i<n-1; i++) {
        cout<<arr[i]<<" ";
    } 
    cout<<"\n";
    return 0;
}