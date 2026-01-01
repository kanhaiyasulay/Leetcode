/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int height(TreeNode* root)
    {
        if(!root) return 0;
        return max(height(root->left), height(root->right)) + 1;
    }
    void diameter(TreeNode* root, int& maxi)
    {
        if(!root) return;
        int leftH = height(root->left);
        int rightH = height(root->right);

        int tot = leftH + rightH;
        maxi = max(maxi, tot);

        diameter(root->left, maxi);
        diameter(root->right, maxi);
    }
    int diameterOfBinaryTree(TreeNode* root) 
    {
        int maxi = 0;
        diameter(root, maxi);
        return maxi;    
    }
};