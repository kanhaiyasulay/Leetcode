class Solution {
public:
    bool checkdigits(char ch) {
        if(ch == '0' || ch == '2' || ch == '3' || ch == '1' || ch == '4' || ch == '5' || ch == '6' || ch == '7' || 
          ch == '8' || ch == '9') return true;
        return false;
    }
    bool checkVowel(char ch) {
        if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;
        return false;
    }
    bool checkConso(char ch) {
        if(ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' && ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U') return true;
        return false;
    }
    bool isValid(string word) {
        if(word.length() < 3) return false;
        bool digitP = false;
        bool vowelP = false;
        bool conso = false;
        for(int i=0; i<word.length(); i++) {
            char ch = word[i];
            if(!checkdigits(ch) && !((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))) return false;
            if(checkVowel(ch)) vowelP = true;
            if(checkConso(ch) && !checkdigits(ch)) conso = true;
        }
        if(vowelP && conso) return true;
        return false;
    }
};