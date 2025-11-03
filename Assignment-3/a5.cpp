
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
   