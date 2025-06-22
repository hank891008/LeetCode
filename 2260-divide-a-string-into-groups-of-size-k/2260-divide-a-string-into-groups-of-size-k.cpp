class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        while(s.size() % k != 0){
            s += fill;
        }
        for(int i = 0; i < s.size(); i+= k){
            ans.emplace_back(s.substr(i, k));
        }
        return ans;
    }
};