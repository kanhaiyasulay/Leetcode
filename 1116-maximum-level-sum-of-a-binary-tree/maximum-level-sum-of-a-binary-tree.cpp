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
    void maxLvl(TreeNode* root, int& ans)
    {
        int maxi = root->val, lvl = 1;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();
            int sum = 0;

            for(int i=0; i<size; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                sum += front->val;

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(sum > maxi)
            {
                maxi = sum;
                ans = lvl;
            }
            lvl++;
        }
    }
public:
    int maxLevelSum(TreeNode* root) 
    {
        int ans = 1;
        maxLvl(root, ans);
        return ans;
    }
};