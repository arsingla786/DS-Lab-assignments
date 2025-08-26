//4.Write a program to convert an Infix expression into a Postfix expression.
#include <bits/stdc++.h>
using namespace std;

int precedence(char op) {
    if (op == '+' ||op == '-') return 1;
    if (op== '*' ||op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}
string infixToPostfix(string expression) {
    stack<char> st;
    string postfix = "";

    for (char ch : expression) {
        if (isalnum(ch)) {
            postfix += ch;
        }
        // If '(' push to stack
        else if (ch == '(') {
            st.push(ch);
        }
        // If ')' pop until '('
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            if (!st.empty() && st.top() == '(') st.pop(); // discard '('
        }
        else {
            while (!st.empty() && precedence(st.top()) >= precedence(ch)) {
                postfix += st.top();
                st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string expression;
    cout << "Enter Infix Expression: ";
    cin >> expression;

    cout << "Postfix Expression: " << infixToPostfix(expression) << endl;
    return 0;
}


 