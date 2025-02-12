class Solution {
public:
    int digitSum(int n)
    {
        int sum = 0;
        while(n > 0)
        {
            sum += n%10;
            n /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++)
        {
            int sum1 = digitSum(nums[i]);
            mp[sum1].push_back(nums[i]);
        }

        // for(auto a:mp)
        // {
        //     cout<<a.first<<". ->. ";
        //     for(auto it:a.second) cout<<it<<".  ";
        //     cout<<endl;
        // }

        int ans = -1;
        for(auto a:mp )
        {
            if(a.second.size() < 2) continue;
            int maxi = 0;
            for(auto it:a.second) maxi = max(maxi, it);

            for(auto& it:a.second) 
            {
                if(it == maxi) 
                {
                    it = 0;
                    break;
                }
            }

            int maxi1 = 0;
            for(auto it:a.second)  maxi1 = max(maxi1, it);

            ans = max(ans, maxi + maxi1);
        }

        return ans;
    }
};