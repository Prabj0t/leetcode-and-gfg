class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        vector<int> v;
        int i = 0;
        while(i < nums1.size()){
            if(map[nums1[i]] == 1){
                i++;
            }
            else{
                map[nums1[i]]++;
                i++;
            }
            
        }
        int j = 0;
        while(j < nums2.size()){
            if(map[nums2[j]] != 1 ){
                j++;
            }
            
            else{
                map[nums2[j]]++; 
                j++;
            }
            
        }
        int k = 0 ;
        while(  k < map.size())
        {
            if(map[k] == 2){
                v.push_back(k);
            }
            k++;
        }
        return v;
        
        #include <unordered_set>
    }
};
//     int intersectionSize(int a[], int n, int b[], int m) {
//          unordered_set<int> setA;
//          int count = 0;
    
//          for (int i = 0; i < n; i++) {
//              setA.insert(a[i]);
//          }
    
//          for (int i = 0; i < m; i++) {
//              if (setA.count(b[i])) {
//              count++;
//              setA.erase(b[i]); // If duplicates are allowed, remove this line
//         }
//     }
//     return count;
// }
