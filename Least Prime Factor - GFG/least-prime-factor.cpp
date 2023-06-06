//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> leastPrimeFactor(int n) {
        // code here
        vector<int> ans;
        int i = 0 ;
        for(int i = 0 ; i <= n ; i++)
        {
            if( i == 0 || i == 1){
                ans.push_back(i);
            }
            else if(i % 2 == 0){
                ans.push_back(2);
            }
            else if(i%2 != 0){
                int a = 3;
                while(a <= i){
                    if(i % a == 0){
                        ans.push_back(a);
                        break;
                    }
                    a = a+2;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        vector<int>ans = ob.leastPrimeFactor(n);
        for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
        cout<<endl;  
    }
    return 0;
}

// } Driver Code Ends