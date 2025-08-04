class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int r = 0, l = 0, n = fruits.size(), maxCnt = 0;

        while(r < n) {
            mp[fruits[r]]++;

            while(mp.size() > 2) {
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0) mp.erase(fruits[l]);
                l++;
            }

            int cnt = 0;
            for(auto a:mp) cnt += a.second;
            
            maxCnt = max(maxCnt, cnt);
            r++;
        }
        return maxCnt;
    }
};