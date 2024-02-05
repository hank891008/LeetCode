class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        map<int, int> m;
        for(int i = 0; i < score.size(); i++){
            m[score[i]] = i;
        }
        vector<string> ans(score.size());
        int cnt = 0;
        for(auto it = m.rbegin(); it != m.rend(); it++){
            auto idx = it->second;
            if(cnt == 0){
                ans[idx] = "Gold Medal";
            }
            else if(cnt == 1){
                ans[idx] = "Silver Medal";
            }
            else if(cnt == 2){
                ans[idx] = "Bronze Medal";
            }
            else{
                ans[idx] = to_string(cnt + 1);
            }
            cnt++;
        }
        return ans;
    }
};