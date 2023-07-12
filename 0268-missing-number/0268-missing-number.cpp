class Solution {
public:
    int missingNumber(vector<int>& nums) {
        
        unordered_map<int,int> mp;
        
        for(int i = 0 ; i < nums.size() ; i++){
            mp[nums[i]]++;
        }
        
        int ans ;
        for(int j = 0 ; j <= nums.size() ; j++){
            if(mp[j] == 0){
                ans = j;
            }
        }
        
//         sort(nums.begin() ,nums.end());
//         int i;
//         for( i = 0 ; i < nums.size() ; i++ ){
//             if(nums[i] != i){
//                 return i;
//             }
//         }
        
//         return i;
        return ans;
    }
};