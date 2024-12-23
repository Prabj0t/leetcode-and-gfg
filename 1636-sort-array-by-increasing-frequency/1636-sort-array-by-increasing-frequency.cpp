class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> freqMap;
        
        for(int i = 0 ; i < nums.size() ; i++){
            freqMap[nums[i]]++;
        }
        
        // Step 2: Define a priority queue with a custom comparator
        auto comp = [](pair<int, int>& a, pair<int, int>& b) {
            // Sort by frequency (ascending), if same frequency by value (descending)
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(comp)> pq(comp);
        
        for(auto it : freqMap){
            pq.push({it.second , it.first});
        }
        
        
        vector<int> ans;
        while (!pq.empty()) {
            int freq = pq.top().first;
            int value = pq.top().second;
            pq.pop();
            for (int i = 0; i < freq; i++) {
                ans.push_back(value);
            }
        }
        
        return ans;
    }
};