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
    string findSameTree(TreeNode* root, unordered_map<string, int>& mp, vector<TreeNode*>& ans)
    {
        if(!root) return "N";

        string str = to_string(root->val) + ", " + findSameTree(root->left, mp, ans) + ", " + findSameTree(root->right, mp, ans);

        if(mp[str] == 1)
            ans.push_back(root);
        
        mp[str]++;

        return str;
    }
public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) 
    {
        unordered_map<string, int> mp;
        vector<TreeNode*> ans;

        findSameTree(root, mp, ans);
        return ans;
    }
};