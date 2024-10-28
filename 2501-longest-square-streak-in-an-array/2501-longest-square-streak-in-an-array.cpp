class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        map<int, int> m;
        for(auto num: nums){
            m[num] = 1;
        }
        int maxx = -1;
        for(auto &[k, v]: m){
            int root = (int)sqrt(k);
            if(root * root == k && m.count(root)){
                m[k] += m[root];
                maxx = max(maxx, m[k]);
            }
        }
        return maxx;
    }
};