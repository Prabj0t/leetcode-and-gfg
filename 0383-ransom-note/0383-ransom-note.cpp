class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char , int> mp1;
        unordered_map<char , int> mp2;
        
        for(auto ch : ransomNote){
            mp1[ch]++;
        }
        
        for(auto ch : magazine){
            if(mp1[ch]){
                mp1[ch]--;
            }
        }
        
//         for(auto ch : ransomNote){
//             if(mp2[ch] < mp1[ch]){
//                 return 0;
//             }
            
//         } 
        
        for(auto ch : ransomNote){
            if(mp1[ch]){
                return 0;
            }
        }
        return 1;
    }
};