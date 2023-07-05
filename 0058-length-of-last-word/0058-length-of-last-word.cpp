class Solution {
public:
    int lengthOfLastWord(string s) {
        int e = s.size()-1;
        int count = 0;
        
        while(e >= 0 && s[e] == ' '){
            e--;   
        }
        
        while(e >= 0 && (s[e] != ' ')){ 
                count++;
                e--;
            }
            
        return count;
    }
};