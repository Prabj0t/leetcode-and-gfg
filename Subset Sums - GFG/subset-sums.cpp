//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void ans(vector<int> &arr, int i, vector<int> &final, int sum ){

  if( i == arr.size()){
    // int sum = 0;
    // for ( int j = 0 ; j < temp.size() ; j++){
    //   sum+=temp[j];
    // }
	final.push_back(sum);
	return;
  }

//   temp.push_back(arr[i]);
  ans(arr , i+1 , final , sum+arr[i]);

//   temp.pop_back();
  ans(arr , i+1 , final, sum);
}


    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int i = 0;
        vector<int> final;
        int sum = 0;
        ans(arr, i, final, sum);
        return final;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends