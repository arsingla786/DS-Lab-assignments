#include <iostream>
#include <stack>
#include <string>
using namespace std;

string reverseString(string str) {
    stack<char> st;
    for (char c : str) {
        st.push(c);
    }
    string reversed = "";
    while (!st.empty()) {
        reversed += st.top();
        st.pop();
    }
    return reversed;
}
 
int main() {
string input = "DataStructure";
cout << "Reversed string =: " << reverseString(input) << endl;
    return 0;
}
