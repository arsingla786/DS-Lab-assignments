
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
