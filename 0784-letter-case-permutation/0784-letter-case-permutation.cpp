class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        queue<pair<string, int>> q;
        q.push({s, 0});
        while(!q.empty()){
            auto [str, idx] = q.front();    q.pop();
            if(idx == s.size()){
                ans.emplace_back(str);
            }
            else if(isalpha(str[idx])){
                str[idx] = tolower(str[idx]);
                q.push({str, idx + 1});
                str[idx] = toupper(str[idx]);
                q.push({str, idx + 1});
            }
            else{
                q.push({str, idx + 1});
            }
        }
        return ans;
    }
};