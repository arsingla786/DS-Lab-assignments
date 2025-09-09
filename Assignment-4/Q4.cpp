#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

void firstNonRepeating(string str) {
    queue<char> q;
    unordered_map<char, int> freq;

    for (char ch : str) {
        // Count frequency
        freq[ch]++;

        // Push current char in queue
        q.push(ch);

        // Remove all repeating characters from front
        while (!q.empty() && freq[q.front()] > 1) {
            q.pop();
        }

        // Print result for current step
        if (q.empty()) {
            cout << -1 << " ";
        } else {
            cout << q.front() << " ";
        }
    }
    cout << endl;
}

int main() {
    string input;
    cout << "Enter a string (without spaces): ";
    cin >> input;

    cout << "Output: ";
    firstNonRepeating(input);
  
    return 0;
}
