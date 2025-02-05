/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    bool found = false;
public:
    void markParent(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent)
    {
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            TreeNode* front = q.front();
            q.pop();

            if(front->left)
            {
                parent[front->left] = front;
                q.push(front->left);
            }
            if(front->right)
            {
                parent[front->right] = front;
                q.push(front->right);
            }
        }
    }
    void bfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent, TreeNode* target, int k, vector<int>& ans)
    {
        unordered_map<TreeNode*, bool> visited;
        visited[target] = true;

        queue<TreeNode*> q;
        q.push(target);

        while(!q.empty())
        {
            int size = q.size();

            if(k-- == 0) break;

            for(int i=0; i<size; i++)
            {
                TreeNode* front = q.front();
                q.pop();

                if(parent[front] && !visited[parent[front]])
                {
                    q.push(parent[front]);
                    visited[parent[front]] = true;
                }
                if(front->left && !visited[front->left])
                {
                    q.push(front->left);
                    visited[front->left] = true;
                }
                if(front->right && !visited[front->right])
                {
                    q.push(front->right);
                    visited[front->right] = true;
                }
            }
        }

        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) 
    {
        vector<int> ans;
        unordered_map<TreeNode*, TreeNode*> parent;
        markParent(root, parent);
        bfs(root, parent, target, k, ans);

        return ans;
    }
};