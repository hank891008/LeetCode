class Solution {
public:
    unordered_map<int, int> m;
    int solve(int x){
        if(m.count(x)){
            return m[x];
        }
        else if(x % 2 == 0){
            return m[x] = 1 + solve(x / 2);
        }
        else{
            return m[x] = 1 + solve(3 * x + 1);
        }
    }
    int getKth(int lo, int hi, int k) {
        m[1] = 0;
        vector<pair<int, int>> v;
        for(int i = lo; i <= hi; i++){
            v.emplace_back(make_pair(i, solve(i)));
        }
        sort(v.begin(), v.end(), [&](pair<int, int > x, pair<int, int> y){
            return x.second < y.second || (x.second == y.second && x.first < y.first);
        });
        return v[k - 1].first;
    }
};