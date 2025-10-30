class Solution {
public:
    int numberOfBeams(vector<string>& bank) 
    {
        int cnt = 0;
        int lastLazers = 0;
        int currLazers = 0;

        for(int i=0; i<bank.size(); i++)    
        {
            for(int j=0; j<bank[0].size(); j++)
            {
                if(bank[i][j] == '1')
                {
                    currLazers++;
                    cnt += lastLazers;
                }
            }
            if(currLazers > 0) 
            {
                lastLazers = currLazers;
                currLazers = 0;
            }
        }

        return cnt;
    }
};