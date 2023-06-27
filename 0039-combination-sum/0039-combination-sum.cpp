class Solution {
public:
    
    void comb(int index, vector<int>& cand , int tar , vector<int> &temp , vector<vector<int>> &ans){
        
        
        if(tar < 0){
            return ;
        }
        if( index == cand.size()){
            if( tar == 0){
            ans.push_back(temp);    
            }
            return;
        } 
        
        
        temp.push_back(cand[index]);
        comb(index   , cand , tar-cand[index] , temp , ans);
        temp.pop_back();
        comb(index+1 , cand , tar , temp , ans );
    }
    
    
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> temp;
        comb(0 , candidates , target , temp , ans);
        
        return ans;
    }
};