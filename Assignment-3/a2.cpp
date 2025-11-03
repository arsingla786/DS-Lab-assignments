//q2get min

#include<iostream>
#include<stack>
using namespace std;
int main(){
    int arr[5] = {2,-1,3,4,2};
    stack<int> s;
    s.push(INT_MAX);
    for(int i=0;i<5;i++){
        if(arr[i]<s.top()){
            s.push(arr[i]);
        }
    }
    cout<<"min element = "<<s.top();
}   

 
