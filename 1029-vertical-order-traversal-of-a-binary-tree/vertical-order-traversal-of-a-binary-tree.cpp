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
    void preorder(TreeNode* root, map<int, multiset<pair<int,int>>>& vertiMp,int verti, int hori)
    {
        if(!root) return;

        vertiMp[verti].insert({hori, root->val});

        preorder(root->left, vertiMp, verti-1, hori+1);
        preorder(root->right, vertiMp, verti+1, hori+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans;
        map<int, multiset<pair<int,int>>> vertiMp;

        preorder(root, vertiMp, 0, 0);

        for(auto it:vertiMp )
        {
            vector<int> temp;
            for(auto a:it.second ) temp.push_back(a.second);
            ans.push_back(temp);
        }
        return ans;
    }
};