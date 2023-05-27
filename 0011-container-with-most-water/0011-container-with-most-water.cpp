class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        // for (int i = 0 ; i < height.size() ; i++){
        //     for( int j = i+1 ; j < height.size() ; j++){
        //         area =max(area, (j-i) * (min(height[i], height[j])));
        //     }
        // }
        int i = 0 , j = height.size()-1;

        while( i < j ){
            area = max( area , (j-i) * (min(height[i], height[j])));
            if( height[i] < height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return area;
    }
};