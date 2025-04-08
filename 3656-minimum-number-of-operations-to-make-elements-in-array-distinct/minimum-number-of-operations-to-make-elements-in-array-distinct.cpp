class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int n = nums.size();
        unordered_set<int> st;
        int idx = -1;

        for(int i=n-1; i>=0; i--)    
        {
            if(st.find(nums[i]) != st.end())
            {
                idx = i+1;
                break;
            }
            st.insert(nums[i]);
        }
        if(st.size() == n)  return 0;

        int valid = n - idx;
        int remove = n - valid;

        return remove%3 == 0 ? remove/3 : (remove/3) + 1;
    }
};