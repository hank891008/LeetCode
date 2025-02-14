class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {
        sort(divisors.begin(), divisors.end());
        int maxx = 0;
        int ans = divisors[0];
        for(auto d: divisors){
            int cnt = 0;
            for(auto num: nums){
                if(num % d == 0){
                    cnt++;
                }
            }
            if(cnt > maxx){
                maxx = cnt;
                ans = d;

            }
        }
        return ans;
    }
};