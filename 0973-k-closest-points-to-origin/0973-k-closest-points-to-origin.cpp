class Solution {
public:
    int distanceCalculate(int a, int b){
        return a*a + b*b;
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, int>> pq ;
        
        for(int i = 0 ; i < points.size() ; i++){
            
            int distance = distanceCalculate(points[i][0], points[i][1]);
            
            pq.push({distance , i});
            
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