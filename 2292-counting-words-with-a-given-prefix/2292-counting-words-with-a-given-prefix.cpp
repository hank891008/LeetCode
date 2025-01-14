class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int ans = 0;
        for(auto word: words){
            ans += (word.find(pref) == 0);
        }
        return ans;
    }
};