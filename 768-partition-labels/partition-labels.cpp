class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int n = s.length();
        vector<int> result;

        for(int i=0; i<n; i++)
        {
            char ch = s[i];
            int lastOcc = i;

            for(int j=i; j<n; j++)
            {
                if(s[j] == ch) lastOcc = j;
            }

            for(int k=i+1; k<=lastOcc; k++)
            {
                char currCh = s[k];
                int newLastOcc = k;
                for(int j=k; j<n; j++)
                {
                    if(s[j] == currCh) newLastOcc = j;
                }
                if(newLastOcc > lastOcc) lastOcc = newLastOcc;
            }
            result.push_back(lastOcc-i+1);
            i = lastOcc;
        }

        return result;
    }
};