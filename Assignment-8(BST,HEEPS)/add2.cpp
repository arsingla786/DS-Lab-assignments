class Solution {
public:
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        return solve(1, n);
    }

    vector<TreeNode*> solve(int start, int end) {
        if (start > end) return {nullptr};

        vector<TreeNode*> result;

        for (int root = start; root <= end; root++) {
            // All left subtrees
            vector<TreeNode*> leftTrees = solve(start, root - 1);
            // All right subtrees
            vector<TreeNode*> rightTrees = solve(root + 1, end);

            // Combine each left × each right
            for (TreeNode* left : leftTrees) {
                for (TreeNode* right : rightTrees) {
                    TreeNode* node = new TreeNode(root);
                    node->left = left;
                    node->right = right;
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};
 