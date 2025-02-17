class Solution {
public:
    bool backtrack(int n, vector<bool>& track, vector<int>& ans, int idx)
    {
        if(idx >= ans.size()) return true;

        if(ans[idx] != -1) 
            return backtrack(n, track, ans, idx+1);

        for(int i=n; i>0; i--)
        {
            if(track[i]) continue;

            // try
            track[i] = true;
            ans[idx] = i;

            // explore
            if(i == 1)
            {
                if(backtrack(n, track, ans, idx+1)) return true;
            }
            else
            {
                int j = idx + i;
                if(j < ans.size() && ans[j] == -1)
                {
                    ans[j] = i;
                    if(backtrack(n, track, ans, idx+1)) return true;
                    ans[j] = -1;
                }
            }
            // undo
            track[i] = false;
            ans[idx] = -1;
        }

        return false;
    }
    vector<int> constructDistancedSequence(int n) 
    {
        vector<bool> track(n+1, false);
        vector<int> ans(n*2-1, -1);

        backtrack(n, track, ans, 0);
        return ans;
    }
};