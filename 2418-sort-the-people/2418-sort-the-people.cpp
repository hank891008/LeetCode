class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>>v;
        for(int i = 0; i < names.size(); i++){
            v.emplace_back(heights[i], names[i]);
        }
        sort(v.begin(), v.end(), [](auto a, auto b){
            return a.first > b.first;
        });
        vector<string>ans;
        for(auto [a, b]: v){
            ans.emplace_back(b);
        }
        return ans;
    }
};