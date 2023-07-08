class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int i = 0 ;
        int j = nums.size()-1;
        
        while( i < j){
            
                
            if(nums[i] == nums[i+1]){    
                int temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                nums[j] = 101;
                j--;    
            }
            if( i == j){
                break;
            }
            if(nums[i] == nums[j]){
                nums[j] = 101;
                j--;
            }
            else{ 
                i++;   
            }
        }
        sort(nums.begin() , nums.end());
        i = 0;
        while( i < nums.size() && nums[i] <= 100 ){
            i++;
        }
        return i;
    }
};