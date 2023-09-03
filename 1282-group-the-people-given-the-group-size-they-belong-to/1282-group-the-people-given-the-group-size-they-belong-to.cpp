class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>>ans;
        unordered_map<int, vector<int>>m;
        for(int i = 0; i < groupSizes.size(); i++){
            m[groupSizes[i]].emplace_back(i);
            if(m[groupSizes[i]].size() == groupSizes[i]){
                ans.emplace_back(m[groupSizes[i]]);
                m[groupSizes[i]].clear();
            }
        }
        return ans;
    }
};