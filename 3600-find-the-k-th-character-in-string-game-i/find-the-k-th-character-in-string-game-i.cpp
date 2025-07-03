class Solution {
public:
    char kthCharacter(int k) 
    {
        string word = "a";
        while(word.length() < k)
        {
            int size = word.length();
            for(int i=0; i<size; i++)
            {
                char ch = word[i];
                if(ch == 'z') word.push_back('a');
                else word.push_back(ch+1);
            }
        }

        return word[k-1];
    }
};