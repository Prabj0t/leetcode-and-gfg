class Solution {
public:
    vector<int> NSL(vector<int>& heights){
        vector<int> ans;
        stack<pair<int,int>> s;
        
        for(int i = 0 ; i < heights.size() ; i++){
            if(s.empty()){
                ans.push_back(-1);
            }
            else if( heights[i] >= s.top().first){
                ans.push_back(s.top().second);
            }
            else if(heights[i] < s.top().first){
                while(!s.empty() && heights[i] < s.top().first){
                    s.pop();
                }
                if(s.empty()){
                    ans.push_back(-1);
                }
                else {
                    ans.push_back(s.top().second);
                }
            }
             s.push({heights[i], i});
        }
        
        return ans;
    }
    
    vector<int> NSR(vector<int>& heights){
        vector<int> ans;
        stack<pair<int,int>> s;
        
        for(int i = heights.size() - 1 ; i >= 0 ; i--){
            if(s.empty()){
                ans.push_back(heights.size()); // NSR boundary is the size of the array
            }
            else if( heights[i] > s.top().first){
                ans.push_back(s.top().second);
            }
            else if(heights[i] <= s.top().first){
                while(!s.empty() && heights[i] <= s.top().first){
                    s.pop();
                }
                if(s.empty()){
                    ans.push_back(heights.size());
                }
                else {
                    ans.push_back(s.top().second);
                }
            }
            s.push({heights[i], i}); // Push as a pair
            
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    int largestRectangleArea(vector<int>& heights) {
        vector<int> Nsl = NSL(heights);
        vector<int> Nsr = NSR(heights);
        
        int maxArea = INT_MIN;
        
        for(int i = 0 ; i < heights.size(); i++){
            int width = Nsr[i] - Nsl[i] - 1; // calculate the width
            int Area = width*heights[i]; //calculate area
            maxArea = max(maxArea , Area);
        }
        
        
        return maxArea;
    }
};