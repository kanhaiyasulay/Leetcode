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
    void maxRow(TreeNode* root, map<int,int>& mp, int lvl)
    {
        if(!root) return;

        mp[lvl] += root->val;
        maxRow(root->left, mp, lvl+1);
        maxRow(root->right, mp, lvl+1);
    }
public:
    int maxLevelSum(TreeNode* root) 
    {
        int lvl = 1;
        map<int, int> mp;
        maxRow(root, mp, lvl);
        int sum = root->val;
        for(auto it:mp )
        {
            if(it.second > sum)
            {
                lvl = it.first;
                sum = it.second;
            }
        }

        return lvl;
    }
};