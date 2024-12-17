class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int totalSum = 0, prefixSum = 0;
        int n = nums.size();
        vector<int> ans(n, 0); // Initialize the answer vector with zeros
        
        // Calculate the total sum of the array
        for (int num : nums) {
            totalSum += num; // Add each element to totalSum
        }
        
        // Iterate through the array to compute the result for each element
        for (int i = 0; i < nums.size(); i++) {
            
            // Contribution of all elements to the left of nums[i]
            // Formula: abs(prefixSum - i * nums[i])
            int leftContribution = abs(prefixSum - i * nums[i]);
            
            // Contribution of all elements to the right of nums[i]
            // Formula: (totalSum - prefixSum - nums[i]) - (n - i - 1) * nums[i]
            int rightContribution = (totalSum - prefixSum - nums[i]) - (n - i - 1) * nums[i];
            
            // Calculate the sum of contributions from both sides
            int sum = leftContribution + rightContribution;
            
            // Store the result for the current index
            ans[i] = sum;
            
            // Update the prefix sum to include nums[i]
            prefixSum += nums[i];
        }
        
        return ans; // Return the result vector
    }
};



// class Solution {
// public:
//     vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        
//         int n = nums.size();
//         vector<int> ans(n, 0);
//         vector<vector<int>> memo(n , vector<int>(n, -1));
//         for(int i = 0 ; i < nums.size() ; i++){
//             int sum1 = 0;
//             for(int j = 0 ; j < nums.size() ; j++){
//                 if(i != j){
//                     if( memo[i][j] == -1){
//                         memo[i][j] = abs(nums[i] - nums[j]);
//                         memo[j][i] = memo[i][j];
//                     }
//                     ans[i] += memo[i][j];
//                 }
//             }
//         }
//         return ans;
//     }
// };