class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // Min-heap to store the pairs with their sum
        priority_queue<pair<int, pair<int, int>>, 
                       vector<pair<int, pair<int, int>>>, 
                       greater<pair<int, pair<int, int>>>> minHeap;

        // Push the first k pairs from nums1 and nums2
        for (int i = 0; i < min(k, (int)nums1.size()); i++) {
            minHeap.push({nums1[i] + nums2[0], {i, 0}});
        }

        vector<vector<int>> ans;

        // Extract k smallest pairs
        while (!minHeap.empty() && k > 0) {
            auto topElement = minHeap.top();
            minHeap.pop();
            int i = topElement.second.first;
            int j = topElement.second.second;

            // Add the corresponding pair to the result
            ans.push_back({nums1[i], nums2[j]});
            k--;

            // If there's a next element in nums2, add the new pair to the heap
            if (j + 1 < nums2.size()) {
                minHeap.push({nums1[i] + nums2[j + 1], {i, j + 1}});
            }
        }

        return ans;
    }
};