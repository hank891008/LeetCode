class Solution {
public:
    string compressedString(string word) {
        vector<string> v(1, "");
        v[0] += word[0];
        for(int i = 1; i < word.size(); i++){
            if(v.back().size() == 9 || v.back()[0] != word[i]){
                v.emplace_back("");
            }
            v.back() += word[i];
        }
        string ans;
        for(int i = 0; i < v.size(); i++){
            ans += ('0' + v[i].size());
            ans += v[i][0];
        }
        return ans;
    }
};