vector<int> rightView(TreeNode* root) {
    if (!root) return {};

    vector<int> result;
    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int levelSize = q.size();
        int rightmost;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();

            // Keep updating → last node at this level becomes rightmost
            rightmost = node->val;

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        result.push_back(rightmost);
    }

    return result;
}
 