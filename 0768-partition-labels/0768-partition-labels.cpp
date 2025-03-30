class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<pair<int, int>> p(26);
        for(int i = 0; i < 26; i++){
            p[i].first = -1;
            p[i].second = -1;
        }
        for(int i = 0; i < s.size(); i++){
            int idx = s[i] - 'a';
            if(p[idx].first == -1){
                p[idx].first = i;
                p[idx].second = i;
            }
            else{
                p[idx].second = i;
            }
        }
        sort(p.begin(), p.end());
        vector<int> v;
        int prev_right = 0, prev_idx = 0;
        for(auto [x, y]: p){
            if(x == -1){
                continue;
            }
            cout << x << ' ' << y << '\n';
            if(x > prev_right){
                v.emplace_back(prev_right - prev_idx + 1);
                prev_idx = prev_right + 1;
            }
            prev_right = max(prev_right, y);
        }
        v.emplace_back(prev_right - prev_idx + 1);
        return v;
    }
};