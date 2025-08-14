//8) Write a program to count the total number of distinct elements in an array of length n.
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
    int i=0;
    for(int j=1;j<n;j++){
        if(arr[j]!=arr[i]){
            
            i++;
        }
    }
    cout<<"unique elements = ";
    cout<<i+1;
}



