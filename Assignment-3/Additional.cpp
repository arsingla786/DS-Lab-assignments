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
/*q4 */
#include <bits/stdc++.h>
using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    int n = temperatures.size();
    vector<int> answer(n, 0);
    stack<int> st; // stores indices of days
    
    for (int i = 0; i < n; i++) {
        while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
            int prevDay = st.top();
            st.pop();
            answer[prevDay] = i - prevDay; // days waited
        }
        st.push(i); // push current day
    }
    
    return answer;
}

int main() {
    vector<int> temperatures = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> result = dailyTemperatures(temperatures);
    
    cout << "Result: ";
    for (int days : result) {
        cout << days << " ";
    }
    cout << endl;
    
    return 0;
}

/*q5 */
#include <bits/stdc++.h>
using namespace std;

bool canTransform(vector<int>& A) {
    int n = A.size();
    vector<int> sortedA = A;
    sort(sortedA.begin(), sortedA.end());  // target order
    
    stack<int> S;
    vector<int> B;
    int i = 0; // pointer in A
    int j = 0; // pointer in sortedA (next needed element)
    
    while (i < n || !S.empty()) {
        // if stack top matches needed element, pop to B
        if (!S.empty() && S.top() == sortedA[j]) {
            B.push_back(S.top());
            S.pop();
            j++;
        }
        // else if we still have elements in A, push into stack
        else if (i < n) {
            S.push(A[i]);
            i++;
        }
        // else we are stuck (cannot match needed element)
        else {
            return false;
        }
    }
    
    // if we successfully matched all
    return (B == sortedA);
}

int main() {
    vector<int> A = {3, 1, 2};  // Example input
    if (canTransform(A)) {
        cout << "Yes, it is possible." << endl;
    } else {
        cout << "No, it is not possible." << endl;
    }
    return 0;
}
   
=======
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


>>>>>>> 00c552a4ec738faf00f3b86a1ffb7f1533c77f19
 
