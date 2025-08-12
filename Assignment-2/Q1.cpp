//BINARY SEARCH
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter sorted array ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<"enter element to search : ";
    int search;
    cin>>search;
    int st=0;
    int end = n-1;
    bool exist =false;
    while(st<=end){
        int mid = (st+end)/2;
        if(arr[mid]==search){
            exist = true;
            break;
        }
        else if(arr[mid]<search){
            end=mid-1;
        }
        else{
            st=mid+1;
        }
    }
    if(exist==false)
cout<<"element does not exist";
    else
    cout<<"element exist";
}