class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_left = 0, ans = 0;
        for(int j = 0; j < values.size(); j++){
            ans = max(ans, values[j] - j + max_left);
            max_left = max(max_left, values[j] + j);
        }
        return ans;
    }
};