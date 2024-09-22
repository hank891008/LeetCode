class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> v(n);
        for(int i = 0; i < n; i++){
            v[i] = i + 1;
        }
        sort(v.begin(), v.end(), [](int x, int y){
            return to_string(x) < to_string(y);
        });
        return v;
    }
};