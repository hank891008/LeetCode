class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int cnt = 0;
        for(auto num: nums){
            cnt += (num % 2 == 0);
            if(cnt >= 2){
                return true;
            }
        }
        return false;
    }
};