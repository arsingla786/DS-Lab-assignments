
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