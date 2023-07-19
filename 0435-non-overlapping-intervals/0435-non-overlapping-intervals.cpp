class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1]; // Sort intervals based on end times
        });
        
        int end = intervals[0][1]; // Initialize end time with the end of the first interval
        int count = 0; // Initialize count of intervals to be removed
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] < end) { // Overlapping interval found
                count++;
            } else {
                end = intervals[i][1]; // Update end time
            }
        }
        
        return count;
    }
};
