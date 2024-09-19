class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string, int> m;
        stringstream ss1(s1), ss2(s2);
        string w;
        while(ss1 >> w){
            m[w]++;
        }
        while(ss2 >> w){
            m[w]++;
        }
        vector<string> ans;
        for(auto [x, y]: m){
            if(y == 1){
                ans.emplace_back(x);
            }
        }
        return ans;
    }
};