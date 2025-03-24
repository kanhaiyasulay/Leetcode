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
    void markParent(TreeNode* root, TreeNode* parentNode, unordered_map<TreeNode*, TreeNode*>& parent)
    {
        if(!root) return;
        markParent(root->left, root, parent);
        markParent(root->right, root, parent);

        parent[root] = parentNode;
    }
    TreeNode* findStart(TreeNode* root, int start)
    {
        if(!root) return NULL;
        if(root->val == start) return root;

        TreeNode* leftCall = findStart(root->left, start);
        TreeNode* rightCall = findStart(root->right, start);

        if(!leftCall) return rightCall;
        return leftCall;
    }
public:
    int amountOfTime(TreeNode* root, int start) 
    {
        if(!root->left && !root->right) return 0;
        TreeNode* begin = findStart(root, start);
        unordered_map<TreeNode*, TreeNode*> parent;
        TreeNode* dummy = new TreeNode(-1);
        markParent(root, dummy, parent);

        unordered_map<TreeNode*, bool> vis;
        vis[begin] = true;

        queue<pair<TreeNode*, int>> q;
        q.push({begin, 0});
        int minute = 0;

        while(!q.empty())
        {
            int size = q.size();

            for(int i=0; i<size; i++)
            {
                TreeNode* node = q.front().first;
                minute = q.front().second;
                q.pop();

                if(node->left && !vis[node->left])
                {
                    q.push({node->left, minute+1});
                    vis[node->left] = true;
                }
                if(node->right && !vis[node->right])
                {
                    q.push({node->right, minute+1});
                    vis[node->right] = true;
                }
                if(parent[node] && !vis[parent[node]] && parent[node] != dummy)
                {
                    q.push({parent[node], minute+1});
                    vis[parent[node]] = true;
                }
            }
        }

        return minute;
    }
};