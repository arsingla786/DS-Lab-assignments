//1-> generate all binary no. from 1 to n using queue
#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {
    queue<string> q;

    // Start with "1"
    q.push("1");

    for (int i = 1; i <= n; i++) {
        string current = q.front();
        q.pop();

        // Print the current binary number
        cout << current << " ";

        // Generate next two binaries
        q.push(current + "0");
        q.push(current + "1");
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << ": ";
    generateBinary(n);

    return 0;
}

//2-> 
#include <iostream>
#include <queue>
using namespace std;

// Function to find index of minimum element within unsorted part of queue
int minIndex(queue<int> &q, int sortIndex) {
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        // If current element is smaller than min and index <= sortIndex
        if (curr <= min_val && i <= sortIndex) {
            min_index = i;
            min_val = curr;
        }
        q.push(curr);
    }
    return min_index;
}

// Move element at min_index to rear
void insertMinToRear(queue<int> &q, int min_index) {
    int min_val;
    int n = q.size();

    for (int i = 0; i < n; i++) {
        int curr = q.front();
        q.pop();

        if (i != min_index) {
            q.push(curr);
        } else {
            min_val = curr;
        }
    }
    q.push(min_val);
}

// Function to sort queue
void sortQueue(queue<int> &q) {
    for (int i = 1; i <= q.size(); i++) {
        int min_index = minIndex(q, q.size() - i);
        insertMinToRear(q, min_index);
    }
}

int main() {
    queue<int> q;
    q.push(11);
    q.push(5);
    q.push(4);
    q.push(21);

    cout << "Original Queue: ";
    queue<int> temp = q;
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    }
    cout << endl;

    sortQueue(q);

    cout << "Sorted Queue: ";
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    return 0;
}
 