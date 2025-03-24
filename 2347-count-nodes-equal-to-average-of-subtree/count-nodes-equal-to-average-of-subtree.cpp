class Solution {
public:
    pair<int, int> subtreeSumAndCount(TreeNode* root) {
        if (!root) return {0, 0};  // {sum, count}
        
        auto left = subtreeSumAndCount(root->left);
        auto right = subtreeSumAndCount(root->right);
        
        int sum = root->val + left.first + right.first;
        int count = 1 + left.second + right.second;
        
        return {sum, count};
    }

    int firstLoop(TreeNode* root) {
        if (!root) return 0;

        auto [sum, count] = subtreeSumAndCount(root);
        int match = (sum / count == root->val) ? 1 : 0;

        return match + firstLoop(root->left) + firstLoop(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        return firstLoop(root);
    }
};
