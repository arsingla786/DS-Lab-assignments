#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};
void bstToDLL(Node* root, Node*& head, Node*& prev) {
    if (!root) return;

    // Left subtree
    bstToDLL(root->left, head, prev);

    if (prev == NULL) {
        head = root; // first node becomes head
    } else {
        prev->right = root;
        root->left = prev;
    }
    prev = root;

    bstToDLL(root->right, head, prev);
}

Node* convertBSTtoDLL(Node* root) {
    Node* head = NULL;
    Node* prev = NULL;
    bstToDLL(root, head, prev);
    return head;
}

Node* mergeDLLs(Node* head1, Node* head2) {
    // Dummy head for easy merging
    Node* dummy = new Node(-1);
    Node* tail = dummy;

    while (head1 && head2) {
        if (head1->data < head2->data) {
            tail->right = head1;
            head1->left = tail;
            head1 = head1->right;
        } else {
            tail->right = head2;
            head2->left = tail;
            head2 = head2->right;
        }
        tail = tail->right;
    }

    // Attach remaining nodes
    if (head1) {
        tail->right = head1;
        head1->left = tail;
    }
    if (head2) {
        tail->right = head2;
        head2->left = tail;
    }

    // The real head is dummy->right
    Node* head = dummy->right;
    if (head) head->left = NULL;

    delete dummy;
    return head;
}

Node* mergeBSTsToDLL(Node* root1, Node* root2) {
    Node* head1 = convertBSTtoDLL(root1);
    Node* head2 = convertBSTtoDLL(root2);

    return mergeDLLs(head1, head2);
}

void printDLL(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->right;
    }
    cout << endl;
}


int main() {
    Node* root1 = new Node(3);
    root1->left = new Node(1);
    root1->right = new Node(5);

    Node* root2 = new Node(4);
    root2->left = new Node(2);
    root2->right = new Node(6);

    Node* mergedDLL = mergeBSTsToDLL(root1, root2);

    cout << "Merged Sorted DLL: ";
    printDLL(mergedDLL);
}
