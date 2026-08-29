class Solution {
public:
    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& temp, int idx)
    {
        if(target == 0)
        {
            result.push_back(temp);
            return;
        }

        for(int i=idx; i<candidates.size(); i++)
        {
            if(i > idx && candidates[i] == candidates[i-1]) continue;
            if(candidates[i] > target) continue;

            temp.push_back(candidates[i]);
            backtrack(candidates, target-candidates[i], result, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> temp;

        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, result, temp, 0);
    
        return result;
    }
};