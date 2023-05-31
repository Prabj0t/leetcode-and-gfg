//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> findSum(vector<int> &a, vector<int> &b) {
	    // code here
	int n = a.size();
    int m = b.size();
    
    int carry = 0;
    vector<int> sum;
    
    int i = n - 1;
    int j = m - 1;
    
    while (i >= 0 || j >= 0 || carry > 0) {
            int digitA = 0;
            int digitB = 0;
        
            if (i >= 0) {
                digitA = a[i];
            }
        
            if (j >= 0) {
                digitB = b[j];
            }
        
            int digitSum = digitA + digitB + carry;
            carry = digitSum / 10;
            digitSum = digitSum % 10;
            sum.push_back(digitSum);
            i--;
            j--;
        }
    
        reverse(sum.begin(), sum.end());
        return sum;
    }

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < m; i++) {
            cin >> b[i];
        }
        Solution ob;
        auto ans = ob.findSum(a, b);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends