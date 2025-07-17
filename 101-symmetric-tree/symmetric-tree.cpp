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
    bool check(TreeNode* p, TreeNode* q)
    {
        if(!p || !q) return p == q;
        if(p->val != q->val) return false;
        bool leftC = check(p->left, q->right);
        bool rightC = check(p->right, q->left);

        return (leftC && rightC);
    }
    bool isSymmetric(TreeNode* root) 
    {
        if(!root->left && !root->right) return true;
        if(!root->left || !root->right) return false;
        return check(root->left, root->right);
    }
};