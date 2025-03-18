class Solution {
public:
    int smallestNumber(int n) {
        vector<int> ans = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
        return *upper_bound(ans.begin(), ans.end(), n) - 1;
    }
};