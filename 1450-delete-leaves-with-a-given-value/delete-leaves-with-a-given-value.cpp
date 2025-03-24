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
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* node)
    {
        if(!root) return;

        markParent(root->left, parent, root);
        markParent(root->right, parent, root);

        parent[root] = node;
    }

    void deleteLeaf(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, int target)
    {
        if(!root) return;

        TreeNode* node = root;
        while(!node->left && !node->right && node->val == target)
        {
            root = parent[node];
            if(root->left == node)  root->left = NULL;
            if(root->right == node) root->right = NULL;

            node = root;
        }
        deleteLeaf(root->left, parent, target);
        deleteLeaf(root->right, parent, target);
    }

    TreeNode* removeLeafNodes(TreeNode* root, int target) 
    {
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* dummy = new TreeNode(-1);
        markParent(root, parent, dummy);
        deleteLeaf(root, parent, target);
        if(root->val == target && !root->left && !root->right) return NULL;
        return root;
    }
};