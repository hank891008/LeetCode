class Solution {
public:
    vector<vector<string>> displayTable(vector<vector<string>>& orders) {
        map<string, int>food;
        map<int, vector<string>>table;
        for(auto order: orders){
            food.insert({order[2], 0});
            table[stoi(order[1])].emplace_back(order[2]);
        }
        vector<vector<string>>ans;
        vector<string>tmp;
        tmp.emplace_back("Table");
        int i = 0;
        for(auto &f: food){
            tmp.emplace_back(f.first);
            f.second = i++;
        }
        ans.emplace_back(tmp);
        tmp.clear();
        for(auto [t, fs]: table){
            tmp.emplace_back(to_string(t));
            int count[food.size()];
            memset(count, 0, sizeof(count));
            for(auto f: fs){
                count[food[f]]++;
            }
            for(int i = 0; i < food.size(); i++){
                tmp.emplace_back(to_string(count[i]));
            }
            ans.emplace_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};