class Solution {
public:
    bool reorderedPowerOf2(int n) 
    {
        string curr = to_string(n);
        sort(curr.begin(), curr.end());

        for(int p=0; p<=29; p++)
        {
            string s = to_string(1 << p);
            sort(s.begin(), s.end());
            if(s == curr) return true;
        }
        return false;
    }
};