class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) 
    {
        vector<int> arr;
        for(auto it:grid )
        {
            for(auto a:it ) arr.push_back(a);
        }

        sort(arr.begin(), arr.end());

        int n = arr.size();
        int median = n/2;

        int num = arr[median];

        int cnt = 0;
        for(auto it:arr )
        {
            int diff = abs(num - it);
            if(diff%x != 0) return -1;
            cnt += diff/x;
        }

        return cnt;
    }
};