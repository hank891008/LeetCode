class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int left_idx[26], right_idx[26];
        memset(left_idx, -1, sizeof(left_idx));
        memset(right_idx, -1, sizeof(right_idx));
        for(int i = 0; i < s.size(); i++){

            if(left_idx[s[i] - 'a'] == -1){
                left_idx[s[i] - 'a'] = i;
            }
            right_idx[s[i] - 'a'] = i;
        }
        int ans = 0;
        for(int i = 0; i < 26; i++){
            unordered_set<int> check;
            if(left_idx[i] != right_idx[i]){
                for(int j = left_idx[i] + 1; j < right_idx[i]; j++){
                    check.insert(s[j]);
                }
            }
            ans += check.size();
        }
        return ans;
    }
};