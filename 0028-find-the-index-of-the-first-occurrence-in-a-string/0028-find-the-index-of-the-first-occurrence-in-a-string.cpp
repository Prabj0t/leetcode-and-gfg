class Solution {
public:
    int strStr(string haystack, string needle) {
        int i = 0 ;
        int j = 0;
        int ans = -1;
        while(i < haystack.size() && j < needle.size()){
            if(haystack[i] == needle[j]){
                if(ans == -1){
                    ans = i;
                }
                i++;
                j++;
            }
            else{
                if(j == 0){
                    i++;
                }
                else{
                    j = 0;
                    i = ans+1;
                    ans = -1;
                }
            }
        }
        if(j != needle.size()){
            return -1;
        }
        else{
            return ans;
        }
    }     
};