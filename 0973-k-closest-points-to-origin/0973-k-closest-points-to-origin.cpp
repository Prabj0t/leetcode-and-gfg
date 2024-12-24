class Solution {
public:
    int distanceCalculate(int a, int b){
        int ans;
        ans = a*a + b*b;
        
        return ans;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        unordered_map<int,int> umap;
        
        
        for(int i = 0 ; i < points.size() ; i++){
            int distance = distanceCalculate(points[i][0], points[i][1]);
            umap[i] = distance;
        }
        
        priority_queue<pair<int, int>> pq ;
        
        for(auto it : umap){
            
            pq.push({it.second , it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }
        
        
        vector<vector<int>> finalAns;
        
        while(!pq.empty()){
            finalAns.push_back(points[pq.top().second]);
            pq.pop();
        }
        
        return finalAns;
    
    }
};