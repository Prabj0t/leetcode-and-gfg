class Solution {
public:
    string longestCommonPrefix(vector<string>& v) {
        string ans=""; // Initialize an empty string to store the common prefix.
        sort(v.begin(),v.end()); // Sort the input vector of strings lexicographically.

        int n=v.size(); // Get the size of the input vector.
        string first=v[0],last=v[n-1]; // Get the first and last strings after sorting.

        // Loop through the characters of the first and last strings until the minimum length is reached.
        for(int i=0;i<min(first.size(),last.size());i++){
            if(first[i]!=last[i]){ // If characters at the current position do not match, return the current common prefix.
                return ans;
            }
            ans+=first[i]; // Append the current character to the common prefix string.
        }

        return ans; // Return the final common prefix.
    }
};
