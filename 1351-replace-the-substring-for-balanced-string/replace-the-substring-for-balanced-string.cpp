class Solution {
public:
    int balancedString(string s) {
        int n = s.size();
        int required = n / 4;
        unordered_map<char, int> count;

        // Step 1: Count the frequency of all characters
        for (char ch : s) {
            count[ch]++;
        }

        // Step 2: Early exit if already balanced
        if (count['Q'] == required && count['W'] == required &&
            count['E'] == required && count['R'] == required)
            return 0;

        int res = n;
        int left = 0, right = 0;

        // Step 3: Use sliding window
        while (right < n)
        {
            count[s[right]]--;

            // Step 4: Check if the remaining string (outside window) is valid
            while (count['Q'] <= required && count['W'] <= required && 
                count['E'] <= required && count['R'] <= required) 
            {
                res = min(res, right - left + 1);
                count[s[left]]++;
                left++;
            }
            right++;
        }

        return res;
    }
};
