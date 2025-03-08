class Solution {
public:
    int minimumRecolors(string blocks, int k) 
    {
        int mini = k, n = blocks.size();

        for(int i=0; i<n; i++)
        {
            int cntBlack = 0;
            int j=i;
            if(i+k > n) return mini;
            for(j=i; j<i+k; j++)
            {
                if(blocks[j] == 'B') cntBlack++;
            }
            mini = min(mini, (j-i)-cntBlack);
        }

        return mini;
    }
};