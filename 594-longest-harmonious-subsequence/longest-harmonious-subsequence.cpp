class Solution {
public:
    int findLHS(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int n = nums.size(), maxi = 0;

        for(int i=0; i<n; i++)
        {
            int j = 0;
            for(j=i+1; j<n; j++)
            {
                if(nums[j]-nums[i] > 1) break;
            }
            if(nums[j-1]-nums[i] == 1) maxi = max(maxi, j-i);
        }

        return maxi;
    }
};
