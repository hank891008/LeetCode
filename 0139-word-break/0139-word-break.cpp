class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> ws(wordDict.begin(), wordDict.end());
        vector<bool> dp(n + 5, false);
        dp[0] = true;
        for(int i = 1; i <= s.size(); i++){
            for(int j = 0; j < i; j++){
                if(dp[j] && ws.count(s.substr(j, (i - 1) - j + 1))){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};