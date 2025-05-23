class Solution {
public:
    bool flipEquiv(TreeNode* root1, TreeNode* root2) 
    {
        if (!root1 && !root2) return true; 
        if (!root1 || !root2) return false;
        if (root1->val != root2->val) return false; // Values must be the same

        // Check if trees are equivalent without flipping OR with flipping
        return (flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right)) ||
               (flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left));
    }
};
