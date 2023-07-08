class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
//         vector<int> ans;
        
//         for( int i = 0 ; i < nums1.size() ; i++){
//             int j;
//             for(  j = 0 ; j < nums2.size() ; j++){
//                 if(nums1[i] == nums2[j]){
//                     break;
//                 }
//             }
//             int k =0;
//             for(k = j+1 ; k < nums2.size() ; k++){
//                 if(nums2[j] < nums2[k]){
//                     ans.push_back(nums2[k]);
//                     break;
//                 }
//             }
//             if( k == nums2.size()){
//                 ans.push_back(-1);
//             }
//         }
        
//         return ans;
//     }
        
//         with stack and unordered map
        
        vector<int> ans (nums1.size(), -1);
        stack<int> s;
        unordered_map<int,int> umap;
        
        for(int i = 0 ; i < nums2.size() ; i++){
            
            while( !s.empty() && s.top() < nums2[i]){
                
                umap[s.top()] = nums2[i];
                s.pop();
            }
            
            s.push(nums2[i]);
        }
        
        for( int j = 0 ; j < nums1.size() ; j++){
            
            if(umap.find(nums1[j]) != umap.end()){
                ans[j] = umap[nums1[j]];
            }
            
        }
        return ans;
    }
};