class Solution {
public:
    void backtrack(vector<int>& candi, int target, vector<vector<int>>& result, vector<int> temp, int idx)
    {
        if(target <= 0) 
        {
            if(target == 0) result.push_back(temp);
            return;
        }
        if(idx >= candi.size()) return;

        temp.push_back(candi[idx]);
        backtrack(candi, target-candi[idx], result, temp, idx);
        temp.pop_back();

        backtrack(candi, target, result, temp, idx+1);
    }
    vector<vector<int>> combinationSum(vector<int>& candi, int target) 
    {
        vector<vector<int>> result;
        vector<int> temp;

        backtrack(candi, target, result, temp, 0);
        return result;
    }
};