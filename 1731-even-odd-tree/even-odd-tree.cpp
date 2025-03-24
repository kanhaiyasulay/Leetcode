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
    void dfs(TreeNode* root, unordered_map<int, vector<int>>& mp, int lvl)
    {
        if(!root) return;
        mp[lvl].push_back(root->val);

        dfs(root->left, mp, lvl+1);
        dfs(root->right, mp, lvl+1);
    }

    bool isEvenOddTree(TreeNode* root) 
    {
        int lvl = 0;
        unordered_map<int, vector<int>> mp;
        dfs(root, mp, lvl);

        for(auto it:mp )
        {
            int minVal = INT_MAX, maxVal = INT_MIN;
            for(auto a:it.second )
            {
                if(it.first%2 == 0)
                {
                    if(maxVal >= a || a%2 == 0) return false;
                    maxVal = max(maxVal, a);
                    minVal = min(minVal, a);
                }
                else
                {
                    if(minVal <= a || a%2 == 1) return false;
                    maxVal = max(maxVal, a);
                    minVal = min(minVal, a);
                }
            }
        }

        return true;
    }
};