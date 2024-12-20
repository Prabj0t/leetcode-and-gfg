class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        
        //calculate the missing integers
        int x; 
        for(int i = 0 ; i < arr.size() ; i++){
            // calculating missing integer till ith 
            x = arr[i] - (i+1);
            if( x >= k ){
                return i+k;
            }
        }
        return k+arr.size();
        
    }
};