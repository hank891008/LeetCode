class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxx = 0, now = 0;
        for(int i = 0; i < k; i++){
            now += (double)nums[i] / k;
        }
        maxx = now;
        for(int i = k; i < nums.size(); i++){
            now = now + (double)nums[i] / k - (double)nums[i - k] / k;
            maxx = max(maxx, now);
        }
        return maxx;
    }
};