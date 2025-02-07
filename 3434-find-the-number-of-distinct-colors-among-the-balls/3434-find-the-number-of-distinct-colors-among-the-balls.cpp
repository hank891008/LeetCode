class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> balls;
        unordered_map<int, int> colors;
        vector<int> ans;
        for(auto q: queries){
            int x = q[0], y = q[1];
            if(balls.count(x)){
                if(--colors[balls[x]] == 0){
                    colors.erase(balls[x]);
                }
            }
            balls[x] = y;
            colors[y]++;
            ans.emplace_back(colors.size());
        }
        return ans;
    }
};