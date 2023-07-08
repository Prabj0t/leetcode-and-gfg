class Solution {
public:
    // int removeDuplicates(vector<int>& nums) {
        
//         int i = 0 ;
//         int j = nums.size()-1;
        
//         while( i < j){
            
                
//             if(nums[i] == nums[i+1]){    
//                 int temp = nums[j];
//                 nums[j] = nums[i];
//                 nums[i] = temp;
//                 nums[j] = 101;
//                 j--;    
//             }
//             if( i == j){
//                 break;
//             }
//             if(nums[i] == nums[j]){
//                 nums[j] = 101;
//                 j--;
//             }
//             else{ 
//                 i++;   
//             }
//         }
//         sort(nums.begin() , nums.end());
//         i = 0;
//         while( i < nums.size() && nums[i] <= 100 ){
//             i++;
//         }
//         return i;
//     }
    
        
//         better version of code 
       int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1)
            return n;

        int idx = 1; // Index to track the position to place the next unique element

        for (int i = 1; i < n; i++) {
            if (nums[i] != nums[i-1]) {
                nums[idx] = nums[i]; // Place the next unique element at the current index
                idx++; // Increment the index to track the position for the next unique element
            }
        }

        return idx; // Return the length of the array with duplicates removed
    }
};