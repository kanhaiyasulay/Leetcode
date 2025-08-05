class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) 
    {
        int n = fruits.size();
        int cnt = 0;

        for(int i=0; i<n; i++)   
        {
            bool isPlaced = false;
            for(int j=0; j<n; j++)
            {
                if(baskets[j] == -1) continue;

                if(baskets[j] >= fruits[i]) 
                {
                    baskets[j] = -1;
                    isPlaced = true;
                    break;
                }
            }
            if(!isPlaced) cnt++;
        }

        return cnt;
    }
};