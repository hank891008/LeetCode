class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curr = 0, ans = 0;
        for(auto g: gain) {
            curr += g;
            ans = max(ans, curr);
        }
        return ans;
    }
};