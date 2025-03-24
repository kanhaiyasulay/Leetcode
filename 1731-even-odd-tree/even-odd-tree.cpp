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
    bool isEvenOddTree(TreeNode* root) 
    {
        int lvl = 0;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            int maxVal = 0, minVal = INT_MAX;

            for(int i=0; i<size; i++)
            {
                TreeNode* front = q.front();
                q.pop();

                if(lvl%2 == 0) 
                {
                    if((maxVal >= front->val) || ((front->val) % 2 == 0)) return false;
                    maxVal = max(maxVal, front->val);
                    minVal = min(minVal, front->val);
                }
                else
                {
                    if((minVal <= front->val) || ((front->val) % 2 == 1)) return false;
                    maxVal = max(maxVal, front->val);
                    minVal = min(minVal, front->val);
                }

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            lvl++;
        }

        return true;
    }
};