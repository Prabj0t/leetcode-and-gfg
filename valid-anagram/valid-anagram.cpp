class Solution {
public:
    bool isAnagram(string s, string t) {
        // If the sizes of s and t are not equal, they can't be anagrams
        if (s.size() != t.size()) {
            return false;
        }

        // Array to count character frequencies, assuming lowercase English letters
        int count[26] = {0};

        // Iterate over both strings simultaneously
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;  // Increment the count for character in s
            count[t[i] - 'a']--;  // Decrement the count for character in t
        }

        // If the strings are anagrams, all counts should be 0
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;  // If any count is non-zero, they are not anagrams
            }
        }

        return true;
    }
};
