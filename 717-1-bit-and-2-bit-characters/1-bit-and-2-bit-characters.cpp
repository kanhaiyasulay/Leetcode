class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) 
    {
        int n = bits.size();

        int cnt1 = 0;
        for(int i=n-2; i>=0; i--)
        {
            if(bits[i] == 0) break;
            cnt1++;
        }

        return cnt1%2 == 0 ? true : false;
    }
};