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
    int height(TreeNode* root, unordered_map<TreeNode*, int>& mp)
    {
        if(!root) return 0;

        int leftH = height(root->left, mp);
        int rightH = height(root->right, mp);

        mp[root] = leftH + rightH;
        return max(leftH, rightH) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) 
    {
        unordered_map<TreeNode*, int> mp;
        height(root, mp);

        int maxi = 0;
        for(auto it:mp ) maxi = max(maxi, it.second);

        return maxi;
    }
};