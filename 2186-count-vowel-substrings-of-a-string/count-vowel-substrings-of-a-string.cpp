class Solution {
public:
    int countVowelSubstrings(string word) 
    {
        int n = word.size(), cnt = 0;
        unordered_map<char, int> freq;
        
        for (int l = 0, r = 0, vowelStart = 0; r < n; r++) 
        {
            if (string("aeiou").find(word[r]) == string::npos) 
            { 
                // Reset if a non-vowel is encountered
                freq.clear();
                l = r + 1;
                vowelStart = l;
                continue;
            }
            
            freq[word[r]]++;

            // When all 5 vowels are present, start counting substrings
            while (freq.size() == 5) 
            {
                freq[word[l]]--;
                if (freq[word[l]] == 0) freq.erase(word[l]);
                l++;
            }
            
            cnt += l - vowelStart; // Count valid substrings
        }
        return cnt;
    }
};
