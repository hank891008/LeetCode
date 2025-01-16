class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size(), l2 = nums2.size();
        int ans = 0;
        if(l2 & 1){
            for(auto num: nums1){
                ans ^= num;
            }
        }
        if(l1 & 1){
            for(auto num: nums2){
                ans ^= num;
            }
        }
        return ans;
    }
};