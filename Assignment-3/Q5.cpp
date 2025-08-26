//5. Write a program for the evaluation of a Postfix expression.
#include <bits/stdc++.h>
using namespace std;
int evaluatePostfix(string expression) {
    stack<int> st;

    for (char ch : expression) {
        
        if (isdigit(ch)) {
            st.push(ch - '0'); 
        }
        else {
            int operand2 = st.top(); st.pop();
            int operand1 = st.top(); st.pop();

            switch (ch) {
                case '+': st.push(operand1 + operand2);
                 break;
                case '-': st.push(operand1 - operand2);
                 break;
                case '*': st.push(operand1 * operand2);
                 break;
                case '/': st.push(operand1 / operand2);
                 break;
                case '^': st.push(pow(operand1, operand2));
         break;
            }
        }
    }

    return st.top(); // final result
}
 
int main() {
    string expression;
    cout << "Enter Postfix Expression: ";
    cin >> expression;

    cout << "Evaluated Result: " << evaluatePostfix(expression) << endl;
    return 0;
}








