#include<iostream>
using namespace std;
int main(){
    int n;
    cin>>n;
    int arr[i];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    int countInversions = 0;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j && arr[i]>arr[j]){
                countInversions++;
            } 
        }
    }
    cout<<"no. of inversions = "<<countInversions;
}