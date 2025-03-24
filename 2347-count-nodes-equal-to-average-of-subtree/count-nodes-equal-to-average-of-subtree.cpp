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
    void secondLoop(TreeNode* root, int& sum, int& n)
    {
        if(!root) return;

        sum += root->val;
        n++;

        secondLoop(root->left, sum, n);
        secondLoop(root->right, sum, n);
    }
    void firstLoop(TreeNode* root, int& cnt)
    {
        if(!root) return;
        int sum = 0, n = 0;
        secondLoop(root, sum, n);
        if(sum/n == root->val) cnt++;

        firstLoop(root->left, cnt);
        firstLoop(root->right, cnt);
    }
    int averageOfSubtree(TreeNode* root) 
    {
        int cnt = 0;
        firstLoop(root, cnt);
        return cnt;
    }
};