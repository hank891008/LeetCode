class Solution {
public:
    int countHomogenous(string s) {
        int MOD = 1e9 + 7;
        string prev;
        prev += s[0];
        map<string, int>m;
        string tmp;
        for(int i = 1; i < s.size(); i++){
            if(prev.back() == s[i]){
                prev += s[i];
            }
            else{
                m[prev]++;
                prev.clear();
                prev += s[i];
            }
        }
        m[prev]++;
        int tot = 0;
        for(auto [x, y]: m){ 
            long long sum = y * ((1 + x.size()) * x.size()) / 2 % MOD;
            tot = (tot + sum) % MOD;
        }
        return tot;
    }
};