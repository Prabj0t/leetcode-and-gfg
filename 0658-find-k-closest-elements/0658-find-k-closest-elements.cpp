class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        for(int i = 0 ; i < arr.size() ; i++){
            int temp = abs(arr[i] - x);
            pq.push({temp, i});
            
            if(pq.size() > k){
                pq.pop();
            }   
        }
        int maxIndex = INT_MIN;
        while(!pq.empty()){
            
            if(pq.top().second > maxIndex){
                maxIndex = pq.top().second;
            }
            pq.pop();
        }
        vector<int> result(arr.begin() + maxIndex-k + 1, arr.begin() + maxIndex + 1);
        return result;
    }
};