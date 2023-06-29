class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        
        //Row and column
        int row = matrix.size();
        int col = matrix[0].size();
        
        
        
        /*Approach 1.assume 2D matrix as 1D matrix and apply binary search simply  */

        int st = 0;
        
        //end element correspond to linear array is at..
        int end = row * col - 1;
        
        //find mid as usual..
        int mid = st + (end - st) / 2;
        
        while (st <= end)
        {
            // conversion of linear to again 2D
            int element = matrix[mid / col][mid % col];
            if (element == target)
            {
                return 1;
            }
            else if (element < target)
            {
                st = mid + 1;
            }
            else{
                end = mid - 1;
            }
            mid = st + (end - st)/2;
        }
        
    return 0; 
    }
};