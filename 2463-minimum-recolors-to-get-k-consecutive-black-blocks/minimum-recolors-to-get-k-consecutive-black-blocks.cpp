class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int mini = k, n = blocks.size(), cntBlack = 0;

        unordered_map<int, int> mp;

        mp[-1] = 0;
        for(int i=0; i<n; i++)
        {
            if(blocks[i] == 'B') cntBlack++;

            mp[i] = cntBlack;

            if(i-k+1 >= 0) mini = min(mini, k-(cntBlack-mp[i-k]));
        }

        return mini;
    }
};