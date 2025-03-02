class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank)
    {
        queue<string> q;
        q.push(startGene);
        int level = 0;

        vector<char> check = {'A', 'C', 'G', 'T'};

        unordered_set<string> vis;
        vis.insert(startGene);

        unordered_set<string> bankCheck;
        for(auto a:bank ) bankCheck.insert(a);

        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string str = q.front();
                q.pop();
                if(str == endGene) return level;

                for(int i=0; i<4; i++)
                {
                    string temp = str;
                    for(int j=0; j<8; j++)
                    {
                        temp[j] = check[i];
                        if(bankCheck.find(temp) != bankCheck.end() && vis.find(temp) == vis.end())
                        {
                            q.push(temp);
                            vis.insert(temp);
                        }
                        temp[j] = str[j];
                    }
                }
            }
            level++;
        }

        return -1;
    }
};