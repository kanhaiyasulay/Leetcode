class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        if(n < 3) return {};

        sort(nums.begin(), nums.end());
        int cnt = 0;
        vector<vector<int>> ans;
        for(int i=0; i<nums.size()-1; i+=3)
        {
            if(nums[i+2]-nums[i] > k) return {};
            vector<int> temp;
            for(int j=i; j<=i+2; j++)
            {
                temp.push_back(nums[j]);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};