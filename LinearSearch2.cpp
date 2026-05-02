/*Build a C++ analytics tool that scans a dataset using linear search
 to count occurrences of a target value and report its first
and last positions efficiently. */
#include<iostream>
using namespace std;

void LinearSearch(float a[], int n, float key){
    int count = 0;
    int first = -1, last = -1;
    for(int i = 0; i < n; i++){
        if(a[i] == key){
            count++;
            if(first == -1){
                first = i;
            }
            last = i;
        }
    }

    if(count == 0){
        cout << "Element not found";
    } else {
        cout << "Count = " << count << endl;
        cout << "First Index = " << first << endl;
        cout << "Last Index = " << last << endl;
    }
}
int main(){
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    float arr[n];
    cout<<"Enter the elements of the array: ";
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    float ele;
    cout<<"Enter the element to be searched: ";
    cin >> ele;
    LinearSearch(arr, n, ele);
}