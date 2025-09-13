class Solution {
public:
    int arr[26] = {0};
    int maxFreqSum(string s) 
    {
        for(int i=0; i<s.length(); i++)
            arr[s[i]-97]++;
        
        int maxVowel = 0, maxConsonant = 0;

        for(int i=0; i<26; i++)
        {
            char ch = i + 'a';

            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                maxVowel = max(maxVowel, arr[i]);
            else 
                maxConsonant = max(maxConsonant, arr[i]);
        }
        return maxVowel + maxConsonant;
    }
};