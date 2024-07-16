class Solution {
public:
    const int MAXN = 1e5 + 5;
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> v(MAXN, 0);
        for(auto cost: costs){
            v[cost]++;
        }
        int ans = 0;
        for(int i = 1; i < MAXN; i++){
            if(i > coins){
                break;
            }
            if(v[i] != 0){
                ans += min(coins / i, v[i]);
                coins -= i * min(coins / i, v[i]);
            }
        }
        return ans;
    }
};