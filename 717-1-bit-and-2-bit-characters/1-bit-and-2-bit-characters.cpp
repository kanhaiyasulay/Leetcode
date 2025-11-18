class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int n = bits.size();
        if(n == 1)   return true;

        int last = bits[0] != 0 ? 1 : -1;
        bool ans = true;
        for(int i=1; i<n; i++)
        {
            int curr = bits[i];
            if(last == 1 && curr == 0) 
            {
                ans = false;
                last = -1;
            }
            else if(last == 1 && curr == 1) 
            {
                ans = false;
                last = -1;
            }
            else if(last == -1) 
            {
                ans = true;
                last = curr != 0 ? curr : -1;
            }
        }

        return ans;
    }
};