class Solution {
public:
    bool areAlmostEqual(string s1, string s2) 
    {
        if(s1.length() != s2.length())     return false;

        for(int i=0; i<s1.length(); i++)
        {
            for(int j=0; j<s1.length(); j++)
            {
                swap(s1[i], s1[j]);
                if(s1 == s2) return true;
                swap(s1[i], s1[j]);
            }
        }

        for(int i=0; i<s2.length(); i++)
        {
            for(int j=0; j<s2.length(); j++)
            {
                swap(s2[i], s2[j]);
                if(s1 == s2) return true;
                swap(s2[i], s2[j]);
            }
        }

        return false;
    }
};