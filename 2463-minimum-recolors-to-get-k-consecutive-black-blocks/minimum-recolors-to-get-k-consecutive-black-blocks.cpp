class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int mini = k, n = blocks.size(), l = 0, r = 0;

        int cntBlack = 0;
        while(r < n)
        {
            if(blocks[r] == 'B') cntBlack++;
            if(r-l+1 > k)
            {
                if(blocks[l] == 'B') cntBlack--;
                l++;
            }

            if(r-l+1 == k) 
            {
                mini = min(mini, r-l+1 - cntBlack);
            }
            r++;
        }

        return mini;
    }
};