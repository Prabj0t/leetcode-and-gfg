//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
vector<int> find(int arr[], int n , int x )
{
    // code here
    int l;
    int s;
    vector<int> ans;
    for( int i = 0 ; i < n ; i++){
        if(arr[i]== x){
            l=i;
            ans.push_back(i);
            break;
        }
    }
    if(ans.size()==0){
        ans.push_back(-1);
        ans.push_back(-1);
        return ans;
    }
    for(int i = l ; i < n ; i++){
        if(arr[i]== x){
            s = i;
        }
    }
    ans.push_back(s);

    // for( int i = n ; i >= l ; i--){
    //     if(arr[i]== x){
    //         ans.push_back(i);
    //         break;
    //     }
// }
    return ans;
}

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,x;
        cin>>n>>x;
        int arr[n],i;
        for(i=0;i<n;i++)
        cin>>arr[i];
        vector<int> ans;
        ans=find(arr,n,x);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
    return 0;
}



// } Driver Code Ends