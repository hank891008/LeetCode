class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int> ans(word.size(), 0);
        long long now = 0;
        for(int i = 0; i < word.size(); i++){
            now = ((now * 10) % m + (word[i] - '0') % m) % m;
            ans[i] = (now == 0);
        }
        return ans;
    }
};