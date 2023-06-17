class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int Max = 0;
        int count = 0;
        int i = 0;
        while( i < nums.size()){
            if( nums [i] == 1){
                count++;
                i++;
            }
            else{
                Max = max( Max, count);
                count = 0;
                i++;
            }
        }
        return max(Max , count);
    }
};