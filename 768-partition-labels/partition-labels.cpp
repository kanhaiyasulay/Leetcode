class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int n = s.length();
        vector<int> result;
        unordered_map<char, int> occ;

        for(int i=0; i<n; i++) 
            occ[s[i]] = i;
        
        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            int lastOcc = occ[ch];

            for(int j=i; j<=lastOcc; j++)
            {
                char nextCh = s[j];
                int newLastOcc = occ[nextCh];
                lastOcc = newLastOcc > lastOcc ? newLastOcc : lastOcc;
            }
            result.push_back(lastOcc-i+1);
            i = lastOcc;
        }

        return result;
    }
};