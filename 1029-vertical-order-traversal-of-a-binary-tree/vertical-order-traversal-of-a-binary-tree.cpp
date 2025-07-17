class Solution {
    void preorder(TreeNode* root, map<int, multiset<pair<int,int>>>& vertiMp,int hori, int verti)
    {
        if(!root) return;

        vertiMp[hori].insert({verti, root->val});

        preorder(root->left, vertiMp, hori-1, verti+1);
        preorder(root->right, vertiMp, hori+1, verti+1);
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>> ans;
        map<int, multiset<pair<int,int>>> vertiMp;

        preorder(root, vertiMp, 0, 0);

        for(auto it:vertiMp )
        {
            vector<int> temp;
            for(auto a:it.second ) temp.push_back(a.second);
            ans.push_back(temp);
        }
        return ans;
    }
};
