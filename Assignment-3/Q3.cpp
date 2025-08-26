//Write a program that checks if an expression has balanced parentheses
#include <iostream>
#include <string>
using namespace std;
#define MAX 100 
class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char c) {
        if (top == MAX - 1) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top == -1) {
            return '\0'; // stack empty
        }
        return arr[top--];
    }

    char peek() {
        if (top == -1) return '\0';
        return arr[top];
    }

    bool isEmpty() {
        return (top == -1);
    }
};

bool isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}
 
// function to check if parentheses are balanced
bool areParenthesesBalanced(string expr) {
    Stack s;

    for (int i = 0; i < expr.length(); i++) {
        char c = expr[i];

        if (c == '(' || c == '{' || c == '[') {
            s.push(c);  // push opening brackets
        } 
        else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty() || !isMatchingPair(s.pop(), c)) {
                return false; // unbalanced
            }
        }
    }

    return s.isEmpty();
}

int main() {
    string expr;
    cout << "Enter an expression: ";
    cin >> expr;

    if (areParenthesesBalanced(expr))
        cout << "yes balanced";
    else
        cout << "not balanced";

    return 0;
}
