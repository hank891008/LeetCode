class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int di = INT_MIN;
        for(int i = 0; i < n; i++) {
            if(colors.back() != colors[i]) {
                di = max(di, n - 1 - i);
                break;
            }
        }
        for(int i = n - 1; i >= 0; i--) {
            if(colors[0] != colors[i]) {
                di = max(di, i);
                break;
            }
        }
        return di;
    }
};