class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int max_left = values[0] + 0;
        int ans = 0;
        for(int j = 1; j < values.size(); j++){
            int right = values[j] - j;
            ans = max(ans, right + max_left);
            max_left = max(max_left, values[j] + j);
        }
        return ans;
    }
};