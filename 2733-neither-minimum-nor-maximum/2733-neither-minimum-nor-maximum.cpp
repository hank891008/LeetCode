class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if(nums.size() < 3){
            return -1;
        }
        int minn = INT_MAX, maxx = INT_MIN;
        int ans = 0;
        for(int num: nums){
            minn = min(minn, num);
            maxx = max(maxx, num);
            if(num > minn && num < maxx){
                return num;
            }
        }
        for(int num: nums){
            if(num > minn && num < maxx){
                return num;
            }
        }
        return -1;
    }
};