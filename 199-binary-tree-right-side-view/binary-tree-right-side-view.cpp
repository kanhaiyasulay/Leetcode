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
    void dfs(TreeNode* root, vector<int>& ans)
    {
        if(!root) return;

        ans.push_back(root->val);
        dfs(root->right, ans);
        if(!root->right) dfs(root->left, ans);
        return;
    }
    void bfs(TreeNode* root, vector<int>& ans)
    {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        bool isFirst = true;

        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();

            if(!front)
            {
                isFirst = true;
                if(!q.empty()) q.push(NULL);
            }
            else
            {
                if(isFirst) 
                {
                    ans.push_back(front->val);
                    isFirst = false;
                }
                if(front->right) q.push(front->right);
                if(front->left) q.push(front->left);
            }
        }
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> ans;
        if(!root) return ans;

        bfs(root, ans);
        return ans;
    }
};