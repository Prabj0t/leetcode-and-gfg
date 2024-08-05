class Solution {
public:
    int strStr(string haystack, string needle) {
        // Edge case: if needle is an empty string, return 0
        if (needle.empty()) return 0;

        int haystackLen = haystack.size();
        int needleLen = needle.size();
        
        // Loop through the haystack
        for (int i = 0; i <= haystackLen - needleLen; ++i) {
            int j = 0;
            
            // Check if the substring matches the needle
            while (j < needleLen && haystack[i + j] == needle[j]) {
                ++j;
            }
            
            // If the entire needle is found, return the starting index
            if (j == needleLen) {
                return i;
            }
        }
        
        // If needle is not found in the haystack, return -1
        return -1;
    }
};