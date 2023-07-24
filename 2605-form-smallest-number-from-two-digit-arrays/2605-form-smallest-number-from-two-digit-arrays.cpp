class Solution {
public:
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin() , nums1.end());
        sort(nums2.begin() , nums2.end());
        int i = 0 ;
        int j = 0;
        unordered_map<int,int> mp;
        while( i < nums1.size()){
            mp[nums1[i++]]++;
        }
        
        while( j < nums2.size()){
            if(mp[nums2[j]] == 1){
                return nums2[j];
            }
            mp[nums2[j++]]++;
        }
        int ans = 0;
        if(nums1[0] < nums2[0]){
            ans = nums1[0]*10 + nums2[0];
        }
        else if(nums1[0] > nums2[0]){
            ans = nums2[0]*10 + nums1[0];
            
        }
        return ans;
    }
};