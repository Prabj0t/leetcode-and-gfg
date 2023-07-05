class Solution {
public:
    
    void comb(vector<int> &arr , int target , vector<int> &temp , set<vector<int>> &ans , int index ){

	   
		    if(target == 0){
			    ans.insert(temp);
                return;
		    }
		    
        for(int j = index ; j < arr.size() ; j++){
            if(arr[j] > target){
                break;
            }
            if(j > index && arr[j] == arr[j-1]){
                continue;
            }
            
                temp.push_back(arr[j]);
	            comb(arr, target - arr[j], temp , ans , j+1 );
	            temp.pop_back();
            }
}
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
	    set<vector<int>> ans;
	    comb(candidates , target , temp , ans , 0);
        
        vector<vector<int>>finall;

	    for(auto &n : ans){
		    finall.push_back(n);
	    }
	    ans.clear();
	    return finall;
    }
    
//     for brute for just make sum changes in combination sum -1 problem ;
};




   
//     void comb(vector<int> &arr , int target , vector<int> &temp , set<vector<int>> &ans , int i ){

// 	    if( i == arr.size()){

// 		    if(target == 0){
// 			    ans.insert(temp);
// 		    }
// 		    return;
// 	    }
//            
//       
//         if(arr[i]<=target ){
//             temp.push_back(arr[i]);
// 	        comb(arr, target - arr[i], temp , ans , i+1 );
// 	        temp.pop_back();
//         }
// 	    comb(arr , target , temp , ans , i+1);
// }
    
//     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
//         sort(candidates.begin(), candidates.end());
//         vector<int> temp;
// 	    set<vector<int>> ans;
// 	    comb(candidates , target , temp , ans , 0);
        
//         vector<vector<int>>finall;

// 	    for(auto &n : ans){
// 		    finall.push_back(n);
// 	    }
// 	    ans.clear();
// 	    return finall;
//     }
    
// //     for brute for just make sum changes in combination sum -1 problem ;
// };