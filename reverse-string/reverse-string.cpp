class Solution {
public:
    void reverseString(vector<char>& s) {
        int first = 0;
        int last = s.size() - 1;
        while (first <= last){
            char temporary = s[first];
            s[first] = s[last];
            s[last] = temporary;
            first++;
            last--;
        }
    }
};