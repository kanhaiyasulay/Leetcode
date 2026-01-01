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
        return max(height(root->left) , height(root->right)) + 1;
    }
    void checkHeight(TreeNode* root, int& maxi)
    {
        if(!root) return;
        
        int leftH = height(root->left);
        int rightH = height(root->right);

        maxi = max(maxi, max(leftH, rightH)+1);
        checkHeight(root->left, maxi);
        checkHeight(root->right, maxi);
    }
    int maxDepth(TreeNode* root) 
    {
        int maxi = 0;
        checkHeight(root, maxi);
        return maxi;
    }
};