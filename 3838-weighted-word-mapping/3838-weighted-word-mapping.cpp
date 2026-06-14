class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans;
        for(auto word: words) {
            int tot = 0;
            for(auto w: word) {
                tot = (tot + weights[w - 'a']) % 26;
            }
            ans += ('z' - tot);
        }
        return ans;
    }
};