class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> m;
        for(int i =0;i<strs.size();i++){
            string ch = strs[i];
            sort(ch.begin(),ch.end());
            m[ch].push_back(strs[i]);
        }
        vector<vector<string>> v(m.size());
        int indc = 0;
        for(auto i : m){
            vector<string> v1 = i.second;
            for(int j = 0;j<v1.size();j++){
                    v[indc].push_back(v1[j]);
            }
            indc++;
        }
        return v;
    }
};