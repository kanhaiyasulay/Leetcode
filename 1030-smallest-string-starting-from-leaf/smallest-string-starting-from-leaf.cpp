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
    bool compareStr(string minStr, string str)
    {
        int i = 0;
        int size = min(minStr.length(), str.length());
        while(i < size)
        {
            if(minStr[i] < str[i]) return false;
            else if(minStr[i] > str[i]) return true;
            i++;
        }
        if(minStr.length() < str.length()) return false;
        return true;
    }
public:
    void dfs(TreeNode* root, string& minStr, string str, TreeNode* mainRoot)
    {
        if(!root) return;
        if(!root->left && !root->right)
        {
            char ch = root->val + 'a';
            str = ch + str;
            if(compareStr(minStr, str))
            {
                minStr = str;
            }
            return;
        }
        char ch = root->val + 'a';
        str = ch + str;

        dfs(root->left, minStr, str, mainRoot);
        dfs(root->right, minStr, str, mainRoot);
    }

    string smallestFromLeaf(TreeNode* root) 
    {
        string minStr = "~";
        string str = "";
        dfs(root, minStr, str, root);
        return minStr;
    }
};