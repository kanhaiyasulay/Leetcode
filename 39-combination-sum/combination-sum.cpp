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
            if(candidates[i] <= target)
            {
                temp.push_back(candidates[i]);
                backtrack(candidates, target-candidates[i], result, temp, i);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
        vector<int> temp;
        int idx = 0;

        backtrack(candidates, target, result, temp, idx);
        return result;    
    }
};