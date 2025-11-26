#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                      vector<int>& postorder, int& postIndex,
                      unordered_map<int, int>& inMap) {

    if (inStart > inEnd) return NULL;
    int rootVal = postorder[postIndex--];
    Node* root = new Node(rootVal);

    int inPos = inMap[rootVal];

    root->right = buildTreeHelper(inorder, inPos + 1, inEnd,
                                  postorder, postIndex, inMap);

    root->left = buildTreeHelper(inorder, inStart, inPos - 1,
                                 postorder, postIndex, inMap);

    return root;
}

Node* buildTree(vector<int>& inorder, vector<int>& postorder) {
    int n = inorder.size();
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++) {
        inMap[inorder[i]] = i;
    }

    int postIndex = n - 1;  // Start from last element of postorder

    return buildTreeHelper(inorder, 0, n - 1,
                           postorder, postIndex, inMap);
}

void preorder(Node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

int main() {
    vector<int> inorder  = {4, 2, 5, 1, 6, 3};
    vector<int> postorder = {4, 5, 2, 6, 3, 1};

    Node* root = buildTree(inorder, postorder);

    cout << "Preorder :";
    preorder(root);
}
