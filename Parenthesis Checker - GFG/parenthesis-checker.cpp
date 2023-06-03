//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        // Your code here
        if(x.size() == 1){
            return 0;
        }
        stack<char> s;
        for( int i = 0 ; i < x.size() ; i++){
            char ch = x[i];
            if( ch == '(' || ch == '[' || ch == '{' ){
                s.push(ch);
            }
            else{
                if( !s.empty() && ((ch == ')' && s.top() != '(') || (ch == '}' && s.top() != '{' ) || (ch == ']' && s.top() != '['))){
                    return 0;
                }
                else{
                    if(!s.empty()){
                        s.pop();
                    }
                    else{
                        return 0;
                    }
                }
            }
        }
        if(!s.empty()){
            return 0;
        }
        return 1;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends