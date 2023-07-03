class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = nums.size()-1;
        int i = 0;
        int ans = 0;
        while(i < nums.size() && j >=0){
            if( nums[i] == val){
                nums[i] = nums[j];
                nums[j] = -1;
                j--;
            }
            else{
                i++;
            }
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i] == -1){
                break;
            }
            ans++;
        }
        return ans;
    }
};