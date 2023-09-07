class Solution {
public:
    int numberOfEmployeesWhoMetTarget(vector<int>& hours, int target) {
        int ans = 0;
        for(auto n: hours){
            ans += (n >= target);
        }
        return ans;
    }
};