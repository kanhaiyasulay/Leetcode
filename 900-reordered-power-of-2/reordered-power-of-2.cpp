class Solution {
public:
    bool permut(string& str, int idx)
    {
        if (idx == str.length()) 
        {
            if (str[0] == '0') return false;
            int num = 0;
            for (auto it : str) 
            {
                num = num * 10 + (it - '0');
            }
            return (num & (num - 1)) == 0;
        }

        for(int i=idx; i<str.length(); i++)
        {
            swap(str[idx], str[i]);
            if(permut(str, idx+1)) return true;
            swap(str[idx], str[i]);
        }
        return false;
    }
    bool reorderedPowerOf2(int n)
    {
        string str = to_string(n);
        return permut(str, 0);
    }
};