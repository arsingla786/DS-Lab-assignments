#include <iostream>
using namespace std;
//create a binary tree firstly
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Function to check if a node is a leaf ->both left and right are null
bool isLeaf(TreeNode* node) {
    return node != NULL && node->left == NULL && node->right == NULL;
}

// Recursive function to find sum of all left leaves
int sumOfLeftLeaves(TreeNode* root) {
    if (root == NULL)
        return 0;

    int sum = 0;

    // If left child exists and is a leaf, add its value
    if (isLeaf(root->left))
        sum += root->left->val;
    else
        // recurse into the left subtree but 
        sum += sumOfLeftLeaves(root->left);

    // Recurse into the right subtree (but don't add right leaves)
    sum += sumOfLeftLeaves(root->right);

    return sum;
}

int main() {
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    cout << "Sum of  left leaves: " << sumOfLeftLeaves(root) << endl;
    return 0;
}
