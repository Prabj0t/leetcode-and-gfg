class Solution {
public:
    int lengthOfLastWord(string s) {
        int e = s.size()-1;
        char ch = s[e];
        int count = 0;
        
        while(ch == ' '){
            e--;   
            ch = s[e];
        }
        
        while(e >= 0){
            ch = s[e];
            if(ch != ' '){   
                count++;
                e--;
            }
            if(ch == ' '){
                break;
            }
        }
        if(e <= 0 && count == 0){
                return 1;
        }
        return count;
    }
};