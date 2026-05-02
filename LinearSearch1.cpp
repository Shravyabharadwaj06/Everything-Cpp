//LINEAR SEARCH IN CPP
#include <iostream>
using namespace std;
void LinearSearch(int a[],int n,int key){
    int i;
    for(i=0;i<n;i++){
        if(a[i]==key){
           cout<<"Element found at index: "<<i<<endl;
        }
    }
}
int main()
{
   int n;
   cout<<"Enter the size of the array: ";
   cin>>n;
   cout<<"Enter the elements of the array: ";
   int arr[n],i,ele;
   for(i=0;i<n;i++){
       cin>>arr[i];
   }
   cout<<"Enter the element to be searched: ";
   cin>>ele;
LinearSearch(arr,n,ele);
    return 0;
}