class Solution {
public:
    void backtrack(vector<int>& candidates, vector<vector<int>>& ans, vector<int>& temp, int target, int idx)
    {
        if(target == 0)
        {
            ans.push_back(temp);
            return;
        }
        if(idx < 0) return;

        for(int i=idx; i>=0; i--)
        {
            if(candidates[i] > target) continue;
            temp.push_back(candidates[i]);
            backtrack(candidates, ans, temp, target-candidates[i], i);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        backtrack(candidates, ans, temp, target, candidates.size()-1);
        return ans;
    }
};
