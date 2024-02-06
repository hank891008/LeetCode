class Solution {
public:
    vector<int> count_alpha(string st){
        vector<int> alpha(26);
        for(int i = 0; i < st.size(); i++){
            alpha[st[i] - 'a']++;
        }
        return alpha;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<vector<int>, vector<string>> m;
        for(auto str: strs){
            m[count_alpha(str)].emplace_back(str);
        }
        vector<vector<string>> ans;
        for(auto [_, v]: m){
            ans.emplace_back(v);
        }
        return ans;
    }
};