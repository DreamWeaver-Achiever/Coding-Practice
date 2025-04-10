#include <iostream>
#include <vector>
using namespace std;
int main() {
    cout<<"Frequency Distribution from 0-100"<<endl;
    int group[10] = {0};
    vector<int> arr = {95, 88, 67, 78, 81, 98, 55, 45, 72, 90};
    for(int i=0; i<arr.size(); i++) { 
        int groupIndex = arr[i] / 10; // Determine the group index (0-9)
        if (groupIndex >= 0 && groupIndex < 10) {
            ++group[groupIndex]; // Increment the frequency count for that group
        }
        cout<<group[i]<<endl;
    }
    cout << "\nFrequency Distribution:" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i * 10 << "-" << (i * 10) + 9 << ": " << group[i] << endl;
    }
    return 0;
}