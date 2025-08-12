//find missing number from a sortedd array 
#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[n];
    cout<<"enter a sorted array  ";
    for(int i=0;i<n;i++){
            cin>>arr[i];
    }
    int missing;
    bool isMissing = false;
    for(int i=0;i<n;i++){
        if(arr[i+1]-arr[i] != 1){
            missing = arr[i]+1;
            isMissing = true;
            break;
        }
    }
    if(isMissing){
        cout<<"missing element  = "<<missing;
    }
    else{
        cout<<"no missing element ";
    }
}