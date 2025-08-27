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

//using stacks
#include<iostream>
#include<stack>
using namespace std;

int main() {
    int arr[5] = {2, 3, 1, 6, 5};
    stack<int> s;
    int ans[5] = {0};

    for(int i = 0; i < 5; i++) {
        while(!s.empty() && s.top() >= arr[i]) {
            s.pop();
        }

        if(s.empty()) {
            ans[i] = -1;
        } else {
            ans[i] = s.top();
        }
        s.push(arr[i]);
    }

    for(int i = 0; i < 5; i++) {
        cout << ans[i] << " ";
    }

    return 0;
}

/*q3   */
#include <iostream>
#include <stack>
using namespace std;

void printNGE(int arr[], int n) {
    int nge[n];
    stack<int> st;
    for (int i = n - 1; i >= 0; i--) {
        // Pop smaller or equal elements
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        if (st.empty()) {
            nge[i] = -1;
        } else {
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << arr[i] << " --> " << nge[i] << endl;
    }
}

int main() {
    int arr[] = {4, 5, 2, 25, 7, 8};
    int n = 6;
    printNGE(arr, n);

}
