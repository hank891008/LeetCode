class Solution {
public:
    int minOperations(vector<string>& logs) {
        int n = 0;
        for(auto log: logs){
            if(log == "../"){
                n -= !(n == 0);
            }
            else if(log == "./"){
                continue;
            }
            else{
                n++;
            }
        }
        return n;
    }
};