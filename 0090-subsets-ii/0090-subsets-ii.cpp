
class Solution {
public:
    
    void ans(vector<int> nums, vector<int> &temp  , int i , vector<vector<int>> &sett){
        
        if( i == nums.size() ){
            sett.push_back(temp);
            return;
        }
        
        temp.push_back(nums[i]);
        ans(nums, temp , i+1 , sett);
        
        temp.pop_back();
        ans(nums, temp , i+1 , sett);
        
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int i = 0;
        vector<int> temp;
        vector<vector<int>> sett;
        set<vector<int>> finall;
        sort(nums.begin(), nums.end());
        ans(nums, temp , i , sett);
        
        for(auto &no: sett) {
            finall.insert(no);
        }
        sett.clear();
        for(auto &no: finall) {
            sett.push_back(no);
        }
        return sett;
    }
};