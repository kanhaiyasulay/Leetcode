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
    bool secondLoop(TreeNode* root)
    {
        if(!root) return false;

        if(root->val == 1) return true;

        bool leftCheck = secondLoop(root->left);
        bool rightCheck = secondLoop(root->right);

        return leftCheck || rightCheck;
    }
    void firstLoop(TreeNode* root)
    {
        if(!root) return;
        if(!secondLoop(root)) 
        {
            root->left = NULL;
            root->right = NULL;
            root->val = -1;
            return;
        }

        firstLoop(root->left);
        firstLoop(root->right);

    }
    void deleteNodes(TreeNode* root)
    {
        if(!root) return;

        if(root->left)
        {
            if(root->left->val == -1) root->left = NULL;
        }
        if(root->right)
        {
            if(root->right->val == -1) root->right = NULL;
        }

        deleteNodes(root->left);
        deleteNodes(root->right);
    }
    TreeNode* pruneTree(TreeNode* root) 
    {
        firstLoop(root);
        deleteNodes(root);
        if(!root->left && !root->right && root->val == -1) return NULL;
        return root;
    }
};