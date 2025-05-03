class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int now1 = 0, maxx1 = 0, now2 = 0, maxx2 = 0;
        for(auto &num: nums){
            now1 = max(0, now1 + num);
            now2 = max(0, now2 - num);
            maxx1 = max(maxx1, now1);
            maxx2 = max(maxx2, now2);
        }
        return max(maxx1, maxx2);
        
    }
};