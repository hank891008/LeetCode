class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int, int>m;
        int ret = 0, now = 0;
        m[0] = 1;
        for(auto num: nums){
            now += num;
            if(m.count(now - k)){
                ret += m[now - k];
            }
            m[now]++;
        }
        return ret;
    }
};