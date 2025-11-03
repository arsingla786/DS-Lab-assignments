
//check if string are anagrams

#include <bits/stdc++.h>
using namespace std;

int main() {
	// your code goes here
    string str1;string str2;
    cin>>str1>>str2;
    sort(str1.begin(),str1.end());
    sort(str2.begin(),str2.end());
    if(str1==str2){
        cout<<"yes";
    }
    else{
        cout<<"no";
    }
}