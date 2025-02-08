class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n = nums.size();
        stack<int> st;
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && st.top() <= nums[i])
                st.pop();
            
            st.push(nums[i]);
        }

        vector<int> nge(n, -1);
        for(int i=n-1; i>=0; i--)
        {
            while(!st.empty() && st.top() <= nums[i]) st.pop();

            if(st.empty()) nge[i] = -1;
            else nge[i] = st.top();

            st.push(nums[i]);
        }

        return nge;
    }
};