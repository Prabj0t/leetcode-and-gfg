class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int , int> mp;
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        int maxi = INT_MIN;
        int ans;
        for(auto i : mp){
            
            if(maxi < i.second){
                maxi = i.second;
                ans = i.first;
            }
        }
        
        return ans;
    }
};