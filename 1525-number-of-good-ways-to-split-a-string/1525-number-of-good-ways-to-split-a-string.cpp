class Solution {
public:
    int numSplits(string s) {
        map<char, int>m1, m2;
        for(auto ss: s){
            m1[ss]++;
        }
        int ans = 0;
        for(int i = s.size() - 1; i >= 1;i--){
            m1[s[i]]--;
            m2[s[i]]++;
            if(m1[s[i]] == 0){
                m1.erase(s[i]);
            }
            ans += (m1.size() == m2.size());
        }
        return ans;
    }
};