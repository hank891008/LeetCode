class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1, r = 1e6 + 5;
        while(l < r){
            int m = (l + r) / 2;
            int now = 0;
            for(auto num: nums){
                now += (num + m - 1) / m;
            }
            if(now <= threshold){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};