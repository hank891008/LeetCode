class Solution {
public:
    int minOperations(vector<string>& logs) {
        stack<int> s;
        for(auto log: logs){
            if(log == "../"){
                if(s.empty()){
                    continue;
                }
                else{
                    s.pop();
                }
            }
            else if(log == "./"){
                continue;
            }
            else{
                s.push(0);
            }
        }
        return s.size();
    }
};