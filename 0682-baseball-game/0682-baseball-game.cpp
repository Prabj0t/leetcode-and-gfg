class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> s;
        int ans = 0;
        for(int i = 0 ; i < operations.size() ; i++){
            if(operations[i] == "C"){
                s.pop();
            }
            else if(operations[i] == "D"){
                s.push(s.top()*2);
            }
            else if(operations[i] == "+"){
                int topint = s.top();
                s.pop();
                int added = s.top()+topint;
                s.push(topint);
                s.push(added);
            }
            else{
                s.push(stoi(operations[i]));
            }
        }
        while(!s.empty()){
            ans = ans + s.top();
            s.pop();
        }
        return ans;
        
    }
};