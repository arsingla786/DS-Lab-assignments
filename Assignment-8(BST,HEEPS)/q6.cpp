#include <iostream>
#include <queue>
#include <vector> 
using namespace std;

int main() {
    vector<int> arr = {30, 16, 20, 15, 10, 8};

    // Min-heap for increasing order
    priority_queue<int, vector<int>, greater<int>> pq;

    // Insert all elements into priority queue
    for (int x : arr)
        pq.push(x);

    cout << "Sorted (increasing): ";
    while (!pq.empty()) {
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << endl;

    return 0;
}
