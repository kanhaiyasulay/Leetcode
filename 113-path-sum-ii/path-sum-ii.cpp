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
    void findPath(TreeNode* root, int targetSum, vector<vector<int>>& ans, vector<int> temp)
    {
        if(!root) return;

        targetSum -= root->val;
        temp.push_back(root->val);

        if(targetSum == 0 && !root->left && !root->right)
        {
            ans.push_back(temp);
        }

        findPath(root->left, targetSum, ans, temp);
        findPath(root->right, targetSum, ans, temp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        findPath(root, targetSum, ans, temp);
        return ans;
    }
};