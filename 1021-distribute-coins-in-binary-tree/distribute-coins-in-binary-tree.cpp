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
    int giveCoins(TreeNode* root, int& moves)
    {
        if(!root) return 0;

        int l = giveCoins(root->left, moves);
        int r = giveCoins(root->right, moves);

        moves += abs(l) + abs(r);
        return l + r + root->val  - 1;
    }
    int distributeCoins(TreeNode* root) 
    {
        int moves = 0;
        giveCoins(root, moves);
        return moves;
    }
};