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
    vector<vector<int>> levelOrderHelper(TreeNode* root)
    {
        vector<vector<int>> ans;
        deque<TreeNode*> dq;
        dq.push_front(root);
        while(!dq.empty())
        {
            int size = dq.size();
            vector<int> temp;
            for(int i=0; i<size; i++)
            {
                TreeNode* back = dq.back();
                temp.push_back(back->val);
                dq.pop_back();

                if(back->left) dq.push_front(back->left);
                if(back->right) dq.push_front(back->right);
            }
            ans.push_back(temp);
        }

        return ans;
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>> ans;
        if(!root)    return ans;

        return levelOrderHelper(root);
    }
};