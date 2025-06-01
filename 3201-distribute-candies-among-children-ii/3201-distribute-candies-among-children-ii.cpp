class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for(int i = 0; i <= min(n, limit); i++){
            if(n - i > 2 * limit){
                continue;
            }
            else{
                int maxx = min(n - i, limit);
                int minn = max(0, n - i - limit);
                ans += maxx - minn + 1;
            }
        }
        return ans;
    }
};