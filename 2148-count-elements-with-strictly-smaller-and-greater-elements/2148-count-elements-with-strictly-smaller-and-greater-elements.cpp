class Solution {
public:
    int countElements(vector<int>& nums) {
        int maxx = INT_MIN, minn = INT_MAX;
        for(auto num: nums){
            maxx = max(maxx, num);
            minn = min(minn, num);
        }
        int cnt = 0;
        for(auto num: nums){
            if(num < maxx && num > minn){
                cnt++;
            }
        }
        return cnt;
    }
};