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
    unordered_set<TreeNode*> deepLeaves(TreeNode* root)
    {
        unordered_set<TreeNode*> st;
        vector<TreeNode*> arr;
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            int size = q.size();

            for(int i=0; i<size; i++)
            {
                TreeNode* front = q.front();
                q.pop();
                arr.push_back(front);

                if(front->left) q.push(front->left);
                if(front->right) q.push(front->right);
            }
            if(q.empty()) 
            {
                int arr_size = arr.size();
                for(int i=0; i<arr_size; i++)
                {
                    st.insert(arr.back());
                    arr.pop_back();
                }
                return st;
            }
            else arr.clear();
        }
        return st;
    }
public:
    TreeNode* LCA(TreeNode* root, unordered_set<TreeNode*>& st)
    {
        if(!root) return NULL;

        if(st.find(root) != st.end())
        {
            return root;
        }

        TreeNode* leftCheck = LCA(root->left, st);
        TreeNode* rightCheck = LCA(root->right, st);

        if(leftCheck && rightCheck) return root;
        if(!leftCheck) return rightCheck;
        return leftCheck;
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        unordered_set<TreeNode*> st = deepLeaves(root);
        TreeNode* lca = LCA(root, st);
        return lca;
    }
};