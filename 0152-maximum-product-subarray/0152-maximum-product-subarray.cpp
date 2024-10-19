class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxx = INT_MIN;
        int now = 1;
        for(int i = 0; i < nums.size(); i++){
            if(now == 0){
                now = 1;
            }
            now *= nums[i];
            maxx = max(maxx, now);
        }
        now = 1;
        for(int i = nums.size() - 1; i >= 0; i--){
            if(now == 0){
                now = 1;
            }
            now *= nums[i];
            maxx = max(maxx, now);
        }
        return maxx;
    }
};