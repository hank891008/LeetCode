class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int dis1 = INT_MAX, dis2 = INT_MAX;
        for(int i = start; i >= 0; i--) {
            if(nums[i] == target) {
                dis1 = start - i;
                break;
            }
        }
        for(int i = start + 1; i < nums.size(); i++) {
            if(nums[i] == target) {
                dis2 = i - start;
                break;
            }
        }
        return min(dis1, dis2);
    }
};