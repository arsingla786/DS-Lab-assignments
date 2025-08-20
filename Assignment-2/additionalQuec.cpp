// User function template for C++

class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairs(vector<int>& arr, int k) {
        // code here
        int countPair=0;

        for(int i=0;i<arr.size()-1;i++){
            for(int j=i+1;j<arr.size();j++){
                if (abs(arr[i]-arr[j])==k){
                    countPair++;
                }
            }
        }
        return countPair;
    }
};

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

//dutch national flag

