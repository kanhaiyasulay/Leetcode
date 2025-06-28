class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        
        vector<int> ans;
        int n = nums.size();

        unordered_map<int, int> mp;
        for(int i=n-k; i<n; i++) mp[temp[i]]++;

        for(auto it:nums ) 
        {
           if(mp.find(it) != mp.end() && mp[it] > 0) 
           {
                ans.push_back(it);
                mp[it]--;
           }
        }

        return ans;
    }
};
