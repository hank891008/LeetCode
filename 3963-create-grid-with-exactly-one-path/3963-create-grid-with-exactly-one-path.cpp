class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> v;
        for(int i = 0; i < m; i++) {
            if (i == 0) {
                v.emplace_back(n, '.');
            } else {
                v.emplace_back(string(n - 1, '#') + string(1, '.'));
            }
        }
        return v;
    }
};