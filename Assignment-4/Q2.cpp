
//first non repeating elements

#include<iostream>
#include<string>
#include<queue>
using namespace std;

int main(){
    string str = "aabbcdde";
    int arr[26] = {0};
    queue<char> q;
    for(int i=0;i<str.length();i++){
        arr[str[i]-'a']++;
        q.push(str[i]);
    }
    
    for(int i = 0;i<str.length();i++){
        if(arr[str[i]-'a']==1){
            cout<<"first non repeating = "<< str[i];
            break;
        }
    }
    
}
 
