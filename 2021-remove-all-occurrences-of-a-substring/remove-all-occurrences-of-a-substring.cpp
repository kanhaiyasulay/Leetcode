class Solution {
public:
    string removeOccurrences(string s, string part) {
        //for solution watch supreme batch strings lecture 2
        //or it is saved in kanhaiyamac as removeOccurrrences.cpp
    if(s.find(part) == string::npos) {
        return s;
    }
    int fount = s.find(part);
    s.erase(fount, part.length());

    return removeOccurrences(s, part);
    }
};