class Solution {
public:
    // Function to find the smallest number formed by combining elements from both arrays
    int minNumber(vector<int>& nums1, vector<int>& nums2) {
        // Sorting the input arrays in ascending order
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        // Using unordered_map to keep track of elements and their occurrences in nums1
        unordered_map<int, int> mp;
        int i = 0, j = 0;

        // Counting occurrences of elements in nums1
        while (i < nums1.size()) {
            mp[nums1[i++]]++;
        }

        // Checking for the first element in nums2 that has only one occurrence in nums1
        while (j < nums2.size()) {
            if (mp[nums2[j]] == 1) {
                return nums2[j];
            }
            mp[nums2[j++]]++;
        }

        // If no element is found with a single occurrence in nums1, return the smallest number formed by the first elements of both arrays
        int ans = 0;
        if (nums1[0] < nums2[0]) {
            ans = nums1[0] * 10 + nums2[0];
        } else if (nums1[0] > nums2[0]) {
            ans = nums2[0] * 10 + nums1[0];
        }

        return ans;
    }
};
