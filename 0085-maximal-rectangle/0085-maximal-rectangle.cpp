class Solution {
public:
        // Function to find Nearest Smaller to Left (NSL)
    vector<int> NSL(vector<int>& heights) {
        vector<int> ans;               
        stack<pair<int, int>> s;       // Stack to store pairs of (height, index)
        
        for (int i = 0; i < heights.size(); i++) {
            // Case 1: Stack is empty, no smaller element to the left
            if (s.empty()) {
                ans.push_back(-1);     // Push -1 as there is no smaller element
            }
            // Case 2: Top of stack is smaller than or equal to the current element
            else if (heights[i] >= s.top().first) {
                ans.push_back(s.top().second); // Index of the smaller element
            }
            // Case 3: Top of stack is greater, find the nearest smaller element
            else {
                while (!s.empty() && heights[i] < s.top().first) {
                    s.pop(); // Pop elements greater than the current height
                }
                if (s.empty()) {
                    ans.push_back(-1); // No smaller element found
                } else {
                    ans.push_back(s.top().second); // Index of the smaller element
                }
            }
            // Push current element and its index to the stack
            s.push({heights[i], i});
        }
        return ans;
    }

    // Function to find Nearest Smaller to Right (NSR)
    vector<int> NSR(vector<int>& heights) {
        vector<int> ans;               
        stack<pair<int, int>> s;       // Stack to store pairs of (height, index)

        for (int i = heights.size() - 1; i >= 0; i--) {
            // Case 1: Stack is empty, no smaller element to the right
            if (s.empty()) {
                ans.push_back(heights.size()); // Push array size as the boundary
            }
            // Case 2: Top of stack is smaller than the current element
            else if (heights[i] > s.top().first) {
                ans.push_back(s.top().second); // Index of the smaller element
            }
            // Case 3: Top of stack is greater, find the nearest smaller element
            else {
                while (!s.empty() && heights[i] <= s.top().first) {
                    s.pop(); // Pop elements greater than or equal to the current height
                }
                if (s.empty()) {
                    ans.push_back(heights.size()); // No smaller element found
                } else {
                    ans.push_back(s.top().second); // Index of the smaller element
                }
            }
            // Push current element and its index to the stack
            s.push({heights[i], i});
        }
        reverse(ans.begin(), ans.end()); // Reverse the result for correct order
        return ans;
    }

    // Function to calculate the largest rectangle area in the histogram
    int largestRectangleArea(vector<int>& heights) {
        vector<int> Nsl = NSL(heights); // Indices of Nearest Smaller to Left
        vector<int> Nsr = NSR(heights); // Indices of Nearest Smaller to Right

        int maxArea = INT_MIN; // Initialize max area to the smallest possible value

        // Calculate the area for each bar in the histogram
        for (int i = 0; i < heights.size(); i++) {
            int width = Nsr[i] - Nsl[i] - 1; // Width of the rectangle
            int area = width * heights[i];  // Area = height * width
            maxArea = max(maxArea, area);   // Update max area if current area is larger
        }
        return maxArea;
    }
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        int col = matrix[0].size();
        int answer = INT_MIN;
        vector<int> v(col, 0);
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < col ; j++){
                if( matrix[i][j] == '0'){
                    v[j] = 0;
                }
                else{
                    v[j] += int(matrix[i][j] - '0');
                }
            }
            
            answer = max(largestRectangleArea(v), answer);
        }
        return answer;
    }
};