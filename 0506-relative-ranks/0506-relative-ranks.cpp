class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq; // Max heap to store scores with indices
        int n = score.size();
        stack<string> s;
        vector<string> ans(n, ""); // Result vector initialized with empty strings
        s.push("Bronze Medal"); // Stack to store top 3 medals
        s.push("Silver Medal");
        s.push("Gold Medal");
        
        for (int i = 0; i < score.size(); i++) {
            pq.push({score[i], i}); // Push score and its index into the heap
        }
        
        int rank = 1; // Starting rank
        while (!pq.empty()) {
            pair<int, int> a = pq.top(); // Get the highest score
            if (!s.empty()) {
                ans[a.second] = s.top(); // Assign medal if within top 3
                s.pop();
            } else {
                ans[a.second] = to_string(rank); // Assign rank as string
            }
            pq.pop();
            rank++; // Increment rank
        }
        
        return ans; // Return the ranks/medals
    }
};
