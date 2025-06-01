class Solution {
public:
    void subs(vector<vector<int>>& ans, vector<int>& candidates, int target, int idx, int sum, vector<int>& temp)
    {
        if(sum >= target)
        {
            if(sum == target) ans.push_back(temp);
            return;
        }
        for(int i=idx; i<candidates.size(); i++)
        {
            temp.push_back(candidates[i]);
            subs(ans, candidates, target, i, sum+candidates[i], temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        subs(ans, candidates, target, 0, 0, temp);
        return ans;
    }
};