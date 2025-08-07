#include <iostream>
using namespace std;

#define MAX 100

void createArray(int arr[], int &n) {
    cout << "Enter number of elements: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n) {
    cout << "Enter Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertElement(int arr[], int &n) {
    if (n >= MAX) {
        cout << "Array is full. Cannot insert." << endl;
        return;
    }
    int pos, value;
    cout << "Enter position (1 to " << n+1 << "): ";
    cin >> pos;
    cout << "Enter value: ";
    cin >> value;

    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = value;
    n++;
    cout << "Element inserted." << endl;
}

void deleteElement(int arr[], int &n) {
    if (n == 0) {
        cout << "Array is empty. Cannot delete." << endl;
        return;
    }
    int pos;
    cout << "Enter position (1 to " << n << "): ";
    cin >> pos;
    
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted." << endl;
}

void linearSearch(int arr[], int n) {
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    bool found = false;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Element found at position " << (i + 1) << endl;
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "Element not found." << endl;
    }
}

int main() {
    int arr[MAX], n = 0;
    int choice;

    do {
        cout << "\n——MENU——\n";
        cout << "1)CREATE\n";
        cout << "2) DISPLAY\n";
        cout << "3) INSERT\n";
        cout << "4) DELETE\n";
        cout << "5.) LINEAR SEARCH\n";
        cout << "6.) EXIT\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createArray(arr, n); break;
            case 2: displayArray(arr, n); break;
            case 3: insertElement(arr, n); break;
            case 4: deleteElement(arr, n); break;
            case 5: linearSearch(arr, n); break;
            case 6: cout << "Exiting program." << endl; break;
            default: cout << "Invalid choice! Try again." << endl;
        }
    } while (choice != 6);
}
