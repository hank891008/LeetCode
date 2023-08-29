class Solution {
public:
    int sum;
    vector<pair<int, int>>v;
    Solution(vector<int>& w) {
        sum = accumulate(w.begin(), w.end(), 0);
        for(int i = 0; i < w.size(); i++){
            v.emplace_back(w[i], i);
        }
        sort(v.begin(), v.end());
        for(int i = 0; i < v.size(); i++){
            cout << v[i].first << ' ' << v[i].second << '\n';
        }
    }
    
    int pickIndex() {
        int r = random() % sum + 1;
        int prob = 0;
        for(int i = 0; i < v.size(); i++){
            prob += v[i].first;
            if(r <= prob){
                cout << r << ' ' << prob << '\n';
                return v[i].second;
            }
        }
        return 0;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */