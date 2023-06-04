//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to return the count of the number of elements in
    // the intersection of two arrays.
    int NumberofElementsInIntersection(int a[], int b[], int n, int m) {
        unordered_map<int, int> map;
        int count = 0;
        int i = 0;
        while(i < n){
            if(map[a[i]] == 1){
                i++;
            }
            else{
                map[a[i]]++;
                i++;
            }
            
        }
        int j = 0;
        while(j < m){
            if(map[b[j]] != 1 ){
                j++;
            }
            
            else{
                map[b[j]]++; 
                j++;
            }
            
        }
        int k = 0 ;
        while(  k < map.size())
        {
            if(map[k] == 2){
                count++;
            }
            k++;
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n], b[m];
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < m; i++) cin >> b[i];
        Solution ob;
        cout << ob.NumberofElementsInIntersection(a, b, n, m) << endl;
    }
    return 0;
}
// } Driver Code Ends