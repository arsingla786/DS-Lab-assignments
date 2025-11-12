 //Implement Heapsort (Increasing/Decreasing order).
#include <iostream>
#include <vector>
using namespace std;

// Function to heapify 
void heapify(vector<int>& arr, int n, int i) {
    int largest = i;          
    int left = 2*i + 1;       
    int right = 2*i + 2; 

    // If left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // If right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest); // Recursively heapify
    }
}

void heapSort(vector<int>& arr) {
    int n = arr.size();

    // Step 1: Build max heap
    for (int i = n / 2 - 1; i >= 0; i--){   
         heapify(arr, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);  // Move current root (max) to end
        heapify(arr, i, 0);    // Heapify the reduced heap
    }
}

int main() {
    vector<int> arr = {30, 16, 20, 15, 10, 8};

    heapSort(arr);

    cout << "Sorted array (increasing order): ";
    for (int x : arr)
        cout << x << " ";
    cout << endl;
 
    return 0;
}








