class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int operations = INT_MAX;

        // first cnt 1's
        int cnt1 = 0;
        for(auto it:nums )    if(it == 1) cnt1++;

        int n = nums.size();
        if(cnt1 > 0) return n - cnt1;

        for(int i=0; i<n-1; i++)
        {
            int gcd = nums[i];
            for(int j=i+1; j<n; j++)
            {
                gcd = __gcd(gcd, nums[j]);
                if(gcd == 1) 
                {
                    operations = min(operations, j-i);
                    break;
                }
            }
        }

        if(operations == INT_MAX) return -1;
        return operations + (n-1);

    }
};