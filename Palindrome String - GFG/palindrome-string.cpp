//{ Driver Code Starts
 
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	
	string reverse( string &S,int  m){
	    int strt = 0 ;
	    int end = m-1;
	    while(strt < end){
	        swap(S[strt], S[end]);
	        strt++;
	        end--;
	    }
	    return S;
	}
	int isPalindrome(string S)
	{
	    // Your code goes here
	    int strt = 0 ;
	    int end = S.size();
	    int mid = strt + (end - strt)/2;
	    string sn = reverse(S, mid);
	    int i = 0;
	    int j;
	    if(end%2 != 0){
	        j = mid+1;
	    }
	    else {
	        j = mid;
	    }
	    while(j < end && i < j){
	        if(sn[i] != sn[j]){
	            return 0;
	        }
	        else{
	            i++;
	            j++;
	        }
	    }
	    return 1;
	}

};

//{ Driver Code Starts.

int main() 
{
   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.isPalindrome(s) << "\n";
   	}

    return 0;
}
// } Driver Code Ends