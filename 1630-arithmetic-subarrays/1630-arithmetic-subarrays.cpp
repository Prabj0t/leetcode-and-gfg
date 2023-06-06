class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        int i = 0;
        int flag = 0;
        while(i < l.size()){
            vector<int> temp(nums.begin()+ l[i] , nums.begin() + r[i]+1);
            sort(temp.begin(), temp.end());
            int diff = temp[1] - temp[0];
            for( int j = 0 ; j < temp.size()-1 ; j++){
                if(temp[j+1] - temp[j] != diff){
                    flag = 1;
                    
                    break;
                }
            }
            if( flag == 1){
                ans.push_back(false);
                flag = 0;
            }
            else{
                ans.push_back(true);    
            }
            i++;
        }
        return ans;
    }
};