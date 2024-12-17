class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int totalSum = 0 , prefixSum = 0;
        int n = nums.size();
        vector<int> ans(n ,0);
        
        for(int num : nums){
            totalSum += num;
        }
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            int leftContribution = abs(prefixSum - i*nums[i]);
            int rightContribution = (totalSum - prefixSum - nums[i]) - (n - i - 1)*nums[i];
            
            int sum = leftContribution + rightContribution;
            
            ans[i] = sum;
            prefixSum += nums[i];
        }
        
        return ans;
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