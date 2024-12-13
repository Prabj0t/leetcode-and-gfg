class Solution {
public:
    string makeGood(string s) {
        stack<int> stack;
        string ans = "";
        for(int i = 0 ; i < s.size() ; i++){
            if(stack.empty()){
                stack.push(s[i]);
            }
            
            else if(!stack.empty() && ((s[i] == stack.top() + 32) || (s[i] + 32  == stack.top()))){
                stack.pop();
            }
            else {
                stack.push(s[i]);
            }
        }
        
        while(!stack.empty()){
            ans += stack.top();
            stack.pop();
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};