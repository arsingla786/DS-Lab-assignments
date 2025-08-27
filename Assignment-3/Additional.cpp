/* q1 Given an array, find the nearest smaller element G[i] for 
every element A[i] in the array such that 
the element has an index smaller than i.*/

#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[5] = { 2 , 3 , 4, 2 ,1};   //ans should be {2 (for 3 ),3(for 4)}
    vector<int> ans;
    int min_element;
    for(int i=0;i<5;i++){
        min_element = -1;
        for(int j=i-1;j>=0;j--){
            if(arr[j]<arr[i]){
                min_element = arr[j];
                break;
        }
    }
    ans.push_back(min_element);
}
    for(auto i:ans){
        cout<<i<<" ";
    }
}

/*q3   */
#include <iostream>
#include <stack>
using namespace std;

void printNGE(int arr[], int n) {
    int nge[n];
    stack<int> st;

    // Traverse from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop smaller or equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If stack is empty, no greater element
        if (st.empty()) {
            nge[i] = -1;
        } else {
            nge[i] = st.top();
        }

        // Push current element
        st.push(arr[i]);
    }
 
    // Print result
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main() {
    int arr[] = {4, 5, 2, 25, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printNGE(arr, n);

    return 0;
}
