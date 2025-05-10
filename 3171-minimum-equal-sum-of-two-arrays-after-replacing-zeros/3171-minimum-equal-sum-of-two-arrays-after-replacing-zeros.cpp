class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0, cnt1 = 0, cnt2 = 0;
        for(auto num: nums1){
            sum1 += num;
            cnt1 += (num == 0);
        }
        for(auto num: nums2){
            sum2 += num;
            cnt2 += (num == 0);
        }
        if((cnt1 == 0 && (sum2 + cnt2 > sum1)) || (cnt2 == 0 && (sum1 + cnt1 > sum2))){
            return -1;
        }
        return max(sum1 + cnt1, sum2 + cnt2);
    }
};