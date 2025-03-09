class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int n = colors.size();
        int ans = 0;
        int cnt = 1;
        int last = colors[0];
        for(int i = 1; i < n + k - 1; i++){
            int idx = i % n;
            if(colors[idx] == last){
                cnt = 1;
                continue;
            }
            cnt++;
            if(cnt >= k){
                ans++;
            }
            last ^= 1;
        }
        return ans;
    }
};