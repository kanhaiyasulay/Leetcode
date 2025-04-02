class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        
        long long result = 0;
        vector<int> leftMaxi(n, 0);
        vector<int> rightMaxi(n, 0);

        leftMaxi[0] = nums[0];
        for (int i = 1; i < n; i++)
            leftMaxi[i] = max(leftMaxi[i - 1], nums[i - 1]);  
        
        rightMaxi[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMaxi[i] = max(rightMaxi[i + 1], nums[i + 1]); 

        for (int i = 1; i < n - 1; i++) 
        {
            long long temp = (long long)(leftMaxi[i] - nums[i]) * rightMaxi[i];
            result = max(result, temp);
        }

        return result;
    }
};
