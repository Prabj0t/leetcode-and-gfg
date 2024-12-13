class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        
        for(int i = 0 ; i < s.size(); i++){
            if(!ans.empty() && (s[i] >= 48 && s[i] <= 57 )){
                ans.pop_back();
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};