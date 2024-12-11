class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if( t.size() != s.size()){
            return false;
        }
        else{
            map<char , int> mapping;
            for (int i = 0 ; i < s.size() ; i++){
                mapping[s[i]]++;
            }

            for (int j = 0 ; j < t.size() ; j++){
                if(mapping[t[j]] == 0){
                    return false;
                }
                else{
                    mapping[t[j]]--;
                }
            }
        }
        return true;
    }
    
};