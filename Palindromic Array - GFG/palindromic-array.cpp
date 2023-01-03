//{ Driver Code Starts
#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:
    int reverseDigits(int num)
    {
        int rev_num = 0;
        while (num > 0) {
            rev_num = rev_num * 10 + num % 10;
            num = num / 10;
        }
        return rev_num;
    }
    int isPalindrome(int x)
    {
        int rev_n = reverseDigits(x);
        if (rev_n == x)
            return 1;
        else
            return 0;
    }   
    
    int PalinArray(int a[], int n)
    {
        for(int i = 0 ; i < n ; i++){
            if(!isPalindrome(a[i])){
                return 0;
            }
        }
        return 1;
    	// code here
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
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends