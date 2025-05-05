class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<string> ans1, ans2;
        int now1 = 0, now2 = 1;
        for(int i = 0; i < n; i++){
            if(groups[i] == now1){
                ans1.emplace_back(words[i]);
                now1 = 1 - now1;
            }
            if(groups[i] == now2){
                ans2.emplace_back(words[i]);
                now2 = 1 - now2;
            }
        }
        return ans1.size() >= ans2.size() ? ans1 : ans2;
    }
};