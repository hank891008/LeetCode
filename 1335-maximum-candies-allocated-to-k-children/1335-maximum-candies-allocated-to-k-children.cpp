class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = *max_element(candies.begin(), candies.end());
        int ans = 0;
        while(l <= r){
            int mid = (l + r) / 2;
            long long cnt = 0;
            for(auto candy: candies){
                cnt += candy / mid;
            }
            if(cnt >= k){
                ans = mid;
                l = mid + 1;
            }
            else{
                r = mid - 1;
            }
        }
        return ans;
    }
};