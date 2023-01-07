//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
   public:
    int findSum(int A[], int N)
    {
    	//code here.
    // 	priority_queue<int> pq;
    	
    // 	for(int i = 0 ; i < N ; i++){
    // 	    pq.push(A[i]);
    // 	}
    	
    // 	int M;
    // 	int m;
    	
    // 	M = pq.top();
    	
    // 	for(int i = 0 ; i < N -1 ; i++){
    // 	    pq.pop();
    // 	}
    	
    // 	m = pq.top();
    	
    // 	int Sum = M + m ;
    	
    // 	return Sum;
    	
    	sort(A, A+N);
    	
    	int Sum = A[0]+A[N-1];
    	return Sum;
    	
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
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	      cin>>arr[i];
	    Solution ob;  
	    int ans=ob.findSum(arr, n);
	    cout<<ans;
	    cout<<"\n";
	}
	return 0;
}

// } Driver Code Ends