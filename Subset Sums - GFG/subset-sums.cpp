//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
void ans(vector<int> &arr, int i, vector<int> &temp, vector<int> &final ){

  if( i == arr.size()){
    int sum = 0;
    for ( int j = 0 ; j < temp.size() ; j++){
      sum+=temp[j];
    }
	final.push_back(sum);
	return;
  }

  temp.push_back(arr[i]);
  ans(arr , i+1 , temp, final);

  temp.pop_back();
  ans(arr , i+1 , temp, final);
}


    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        int i = 0;
        vector<int> temp;
        vector<int> final;
        ans(arr, i, temp, final);
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