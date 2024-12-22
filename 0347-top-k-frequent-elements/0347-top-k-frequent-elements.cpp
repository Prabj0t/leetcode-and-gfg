class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> umap;
        
        for(int i = 0 ; i < nums.size() ; i++){
            umap[nums[i]]++;
        }
        
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        for(auto it : umap){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        vector<int> ans;
        while(!pq.empty()){
            ans.insert(ans.begin(), pq.top().second);
            pq.pop();
        }
        
        return ans;
        
    }
};