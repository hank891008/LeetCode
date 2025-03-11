class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> a, b, c;
        for(int i = 0; i < n; i++){
            if(s[i] == 'a'){
                a.emplace_back(i);
            }
            else if(s[i] == 'b'){
                b.emplace_back(i);
            }
            else{
                c.emplace_back(i);
            }
        }
        a.emplace_back(n);
        b.emplace_back(n);
        c.emplace_back(n);
        int ans = 0;
        for(int i = 0; i < n; i++){
            int next_a = *lower_bound(a.begin(), a.end(), i);
            int next_b = *lower_bound(b.begin(), b.end(), i);
            int next_c = *lower_bound(c.begin(), c.end(), i);
            ans += (n - max({next_a, next_b, next_c}));
        }
        return ans;
    }
};