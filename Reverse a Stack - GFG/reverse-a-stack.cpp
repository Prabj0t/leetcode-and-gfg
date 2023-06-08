//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    void insert_at_bottom(stack<int> &st , int x){
        if(st.empty()){
            st.push(x);
            return;
        }
        int a = st.top();
        st.pop();
        insert_at_bottom(st , x);
        st.push(a);
        return;
    }
    void Reverse(stack<int> &St){
        if(St.empty()){
            return;
        }
        int x = St.top();
        St.pop();
        Reverse(St);
        
        insert_at_bottom(St , x);
        return;
    }
};

//{ Driver Code Starts.


int main(){
    int T;
    cin>>T;
    while(T--){
        int N;
        cin>>N;
        stack<int> St;
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            St.push(x);
        }
        Solution ob;
        ob.Reverse(St);
        vector<int>res;
        while(St.size())
        {
            res.push_back(St.top());
            St.pop();
        }
        for(int i = res.size()-1;i>=0;i--)
        {
            cout<<res[i]<<" ";
        }
        
        cout<<endl;
    }
}
// } Driver Code Ends