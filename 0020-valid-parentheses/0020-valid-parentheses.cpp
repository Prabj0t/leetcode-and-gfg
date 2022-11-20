class Solution {
public:
    bool isValid(string s) {
        stack<char> stack;
        
        for (int i = 0 ; i < s.length() ; i++)
        {
            char ch = s[i];
            
            if(ch == '(' || ch == '{' || ch == '[')
            {
                stack.push(ch);
            }
            else 
            {
                
                if(!stack.empty() && ( (ch == ')' && stack.top()=='(' )|| (ch == '}' && stack.top()=='{') || (ch == ']' && stack.top()=='[') ) )
                {
                    stack.pop();
                }
                else
                {    
                    return 0;
                }
            }
            
        }
        if(!stack.empty())
        {
            return 0;
        }
        else
        {
        return 1;
        }
    }
};