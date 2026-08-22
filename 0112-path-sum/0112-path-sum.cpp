class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Empty tree
        if (root == nullptr)
            return false;

        // Leaf node
        if (root->left == nullptr && root->right == nullptr)
            return targetSum == root->val;

        // Check left or right subtree
        return hasPathSum(root->left, targetSum - root->val) ||
               hasPathSum(root->right, targetSum - root->val);
    }
};