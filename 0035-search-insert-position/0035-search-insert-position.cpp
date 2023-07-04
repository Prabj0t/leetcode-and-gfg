class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int f = 0 ;
        int l = nums.size() - 1;
        int mid;
        while(f <= l){
            mid = f + (l - f)/2;
            
            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                l = mid-1;
            }
            else{
                f = mid + 1;
            }
        }
           return l+1;
        
    }
};