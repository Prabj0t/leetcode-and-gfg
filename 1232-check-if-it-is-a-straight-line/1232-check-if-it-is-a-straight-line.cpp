class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int diff1 = coordinates[1][0] - coordinates[0][0];
        int diff2 = coordinates[1][1] - coordinates[0][1];
        for( int i = 2 ; i < coordinates.size(); i++){
            
                
            if(diff2 * (coordinates[i][0] - coordinates[0][0]) != diff1 * (coordinates[i][1] - coordinates[0][1])){
                return 0;
            }
        }
        return 1;   
    }
};