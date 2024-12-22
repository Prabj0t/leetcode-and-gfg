class Solution {
public:
    
    string frequencySort(string s) {
        int n = s.size();
        unordered_map<char, int> freqMap;
        
        for(char ch : s){
            freqMap[ch]++;
        }
        
        
        priority_queue<pair<int, char>> pq;
        for (const auto& it : freqMap) {
            pq.push({it.second, it.first}); // Frequency as key, character as value
        }
        
        string ans = "";
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            
            ans.append(temp.first , temp.second);
        }
        return ans;
    }
};