class Solution {
public:
    int numberOfSubstrings(string s) 
    {
        int result = 0;
        int n = s.length();

        vector<int> cumSumOnes;
        int one = 0;
        for(auto it:s )
        {
            if(it == '1') one++;
            cumSumOnes.push_back(one);
        }

        for(int i=0; i<n; i++)
        {
            for(int j=i; j<n; j++)
            {
                int ones = cumSumOnes[j] - ((i-1 >= 0) ? cumSumOnes[i-1] : 0);
                int zeros = (j-i+1) - ones;

                // if not dominant
                if((zeros*zeros) > ones)
                {
                    int moreOnes = (zeros*zeros) - ones;
                    j += moreOnes - 1;
                }
                else if((zeros*zeros) == ones) result++;
                else // (zeros*zeros) < ones 
                {
                    result++;
                    int wasteIndx = sqrt(ones) - zeros;

                    if(wasteIndx + j >= n) 
                    {
                        result += (n-j-1);
                        break;
                    }
                    else
                    {
                        result += wasteIndx;
                        j = wasteIndx + j;
                    }
                }
            }
        }

        return result;
    }
};