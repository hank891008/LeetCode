class Solution {
public:
    map<pair<int, int>, int> m;
    int solve(vector<int>&v, int idx, int target){
        if(idx == v.size()){
            return target == 0;
        }
        if(m.count({idx, target})){
            return m[{idx, target}];
        }
        return m[{idx, target}] = solve(v, idx + 1, target - v[idx]) + solve(v, idx + 1, target + v[idx]);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, 0, target);
    }
};