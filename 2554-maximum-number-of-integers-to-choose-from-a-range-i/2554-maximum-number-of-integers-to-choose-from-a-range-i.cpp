class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        set<int> s(banned.begin(), banned.end());
        int tot = 0, cnt = 0;
        for(int i = 1; i <= n; i++){
            if(!s.count(i) && tot + i <= maxSum){
                tot += i;
                cnt++;
            }
            if(tot > maxSum){
                break;
            }
        }
        return cnt;
    }
};