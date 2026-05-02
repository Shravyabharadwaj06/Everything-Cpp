/*BINARY SEARCH*/
#include <iostream>
using namespace std;
int BinarySearch(float a[], int n, float key){
    int low = 0, high = n - 1;
    while(low <= high){
        int mid = low + (high - low) / 2;
        if(a[mid] == key){
            return mid;
        } else if(a[mid] < key){
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // Element not found
}
int main(){
    int n;
    cin>>n;
    float arr[n],key;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }   
    cin >> key;
    int result = BinarySearch(arr, n, key);
    if(result != -1){
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found" << endl;
    }
    return 0;
}