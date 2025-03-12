class Solution {
public:
    long long countOfSubstrings(string word, int k) 
    {
        int n = word.size(), cons = 0;
        long long cnt = 0;
        unordered_map<char, int> freq;

        vector<int> nextCons(n, n);
        int consIdx = n;
        for(int i=n-1; i>=0; i--)
        {
            nextCons[i] = consIdx;
            if(string("aeiou").find(word[i]) == string::npos)
            {
                consIdx = i;
            }
        }

        for(int r=0, l=0; r<n; r++)
        {
            if(string("aeiou").find(word[r]) == string::npos)
            {
                cons++;
            }
            else
            {
                freq[word[r]]++;
            }

            while(cons > k)
            {
                if(string("aeiou").find(word[l]) == string::npos)
                {
                    cons--;
                }
                else
                {
                    freq[word[l]]--;
                    if(freq[word[l]] == 0) freq.erase(word[l]);
                }
                l++;
            }
            while(freq.size() == 5 && cons == k)
            {
                cnt += nextCons[r] - r;
                if(string("aeiou").find(word[l]) == string::npos)
                {
                    cons--;
                }
                else 
                {
                    freq[word[l]]--;
                    if(freq[word[l]] == 0) freq.erase(word[l]);
                }
                l++;
            }
        }

        return cnt;
    }
};
