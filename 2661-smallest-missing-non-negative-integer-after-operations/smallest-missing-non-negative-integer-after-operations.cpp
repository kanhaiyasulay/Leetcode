class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) 
    {
        int n = nums.size();
        unordered_map<int, int> mp;    

        for(auto it:nums ) 
        {
            if(it >= 0) 
                mp[it%value]++;
            else 
            {
                int num = ((it%value) + value) % value;
                mp[num]++;
            }
        }

        int i = 0;
        while(!mp.empty())
        {
            int num = i%value;
            if(mp.find(num) == mp.end()) 
                return i;
            else
            {
                mp[num]--;
                if(mp[num] == 0) mp.erase(num);
            }
            i++;
        }

        return i;
    }
};