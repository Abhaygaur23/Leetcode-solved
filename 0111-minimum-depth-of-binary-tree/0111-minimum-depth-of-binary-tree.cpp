class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;

        // Only right subtree exists
        if (root->left == NULL)
            return 1 + minDepth(root->right);

        // Only left subtree exists
        if (root->right == NULL)
            return 1 + minDepth(root->left);

        // Both children exist
        return 1 + min(minDepth(root->left),
                       minDepth(root->right));
    }
};