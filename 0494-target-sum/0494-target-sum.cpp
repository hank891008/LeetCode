class Solution {
private:
    map<pair<int, int>, int> m;
    vector<int> v;
public:
    int solve(int idx, int target){
        if(idx == v.size()){
            return target == 0;
        }
        if(m.count({idx, target})){
            return m[{idx, target}];
        }
        return m[{idx, target}] = solve(idx + 1, target - v[idx]) + solve(idx + 1, target + v[idx]);
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        v = nums;
        return solve(0, target);
    }
};