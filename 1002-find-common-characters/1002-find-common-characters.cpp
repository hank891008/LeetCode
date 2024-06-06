class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<int> alpha(26, 105);
        for(int i = 0; i < words.size(); i++){
            vector<int> tmp(26, 0); 
            for(int j = 0; j < words[i].size(); j++){
                tmp[words[i][j] - 'a']++;
            }
            for(int j = 0; j < 26; j++){
                alpha[j] = min(alpha[j], tmp[j]);
            }
        }
        vector<string> ans;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < alpha[i]; j++){
                ans.emplace_back(string(1, 'a' + i));
            }
        }
        return ans;
        
    }
};