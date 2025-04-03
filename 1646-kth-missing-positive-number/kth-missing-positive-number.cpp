class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) 
    {
        int n = arr.size();
        vector<int> ans;
        for(int idx=0, i=1; i<arr[n-1]+1; i++)
        {
            if(idx >= n) ans.push_back(i);
            else if(arr[idx] == i) idx++;
            else ans.push_back(i);
        }

        int size = ans.size();
        if(k > ans.size()) 
        {
            int num = k-size;
            return arr[n-1] + num;
        }
        return ans[k-1];
    }
};