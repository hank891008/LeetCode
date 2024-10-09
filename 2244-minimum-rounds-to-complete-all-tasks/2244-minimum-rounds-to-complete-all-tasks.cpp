class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int, int> m;
        for(auto t: tasks){
            m[t]++;
        }
        int ans = 0;
        for(auto [_, cnt]: m){
            if(cnt < 2){
                return -1;
            }
            else{
                ans += cnt / 3 + (cnt % 3 != 0);
            }
        }
        return ans;
    }
};