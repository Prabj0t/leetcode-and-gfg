class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        for(int j = 1 ; j <= nums.size() ; j++){
            if(mp[j] == 0){
                ans.push_back(j);
            }
        }
        
        return ans;
    }
};