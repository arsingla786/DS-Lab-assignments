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
