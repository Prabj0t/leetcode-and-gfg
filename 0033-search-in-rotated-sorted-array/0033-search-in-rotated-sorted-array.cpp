class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int lo = 0 , hi = nums.size() - 1;
        
        while( lo < hi){
            int mid = (lo+hi)/2;
            if( nums[mid] > nums[hi]){
                lo = mid+1;
            }
            else{
                hi = mid;
            }
        }
        
        int k = lo;
        
        lo = 0 ;
        hi = nums.size() - 1;
        
        while(lo <= hi){
            int mid = (lo+hi)/2;
            
            int realmid = (k+mid)%nums.size();
            
            if( nums[realmid] == target){
                return realmid;
            }
            else if( nums[realmid] > target){
                hi = mid - 1;
            }
            else if ( nums[realmid] < target){
                lo = mid + 1;
            }
        }
        return -1;
    }
};