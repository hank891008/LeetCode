class Solution {
public:
    vector<string> cellsInRange(string s) {
        vector<string> ans;
        for(int i = s[0]; i <= s[3]; i++){
            for(int j = s[1]; j <= s[4]; j++){
                string tmp;
                tmp += char(i);
                tmp += char(j);
                ans.emplace_back(tmp);
            }
        }
        return ans;
    }
};