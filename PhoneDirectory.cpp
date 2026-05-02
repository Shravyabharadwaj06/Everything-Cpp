/*This project implements a phone directory using Binary Search in C++. 
It efficiently searches sorted names and displays contacts. The search is 
case-sensitive and requires exact input matching.*/
//Search for name and contact
#include<iostream>
#include<string>
using namespace std;
struct Directory{
    string name;
    string contact;
};
int main(){
   Directory directory[10] = {
        {"Alex", "+91 90000 00001"},
        {"Ben", "+91 90000 00002"},
        {"Carol", "+91 90000 00003"},
        {"Dereck", "+91 90000 00004"},
        {"Eesha", "+91 90000 00005"},
        {"Ganesh", "+91 90000 00006"},
        {"Harsh", "+91 90000 00007"},
        {"Inaya", "+91 90000 00008"},
        {"Joe", "+91 90000 00009"},
        {"Karl", "+91 90000 00010"}
    };
    int start=0,end=9;
    string key;
    while(true){ 
    cout<<"Enter the name you want to search: ";
    getline(cin,key);
    while(start<=end){
       int mid=(start+end)/2;
        if(directory[mid].name==key){
            cout<<directory[mid].name<<" : "<<directory[mid].contact;
            return 0;
        }else if(directory[mid].name<key){
            start=mid+1;;
        }else if(directory[mid].name>key){
            end=mid-1;
        }
    }}
    cout<<"Contact Not Found"<<endl;
}