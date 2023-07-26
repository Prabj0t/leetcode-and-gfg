//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        if(s == 0){
            return {-1};
        }
        int lidx = 0;
        int ridx = 0;
        int sum = 0;
        vector<int> ans;
        while(lidx <= ridx && ridx <= n){
            if( sum > s){
                sum = sum - arr[lidx];
                lidx++;
            }
            
            if(sum < s){
                sum += arr[ridx];
                ridx++;
            }
            if( sum == s){
                ans.push_back(++lidx);
                ans.push_back(ridx);
                break;
            }
        }
        if( ans.empty() ){
            ans.push_back(-1);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends