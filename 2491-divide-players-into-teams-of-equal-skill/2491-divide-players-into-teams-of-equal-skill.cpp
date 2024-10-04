class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        unordered_map<long long, int> m;
        int target = 0;
        for(auto s: skill){
            m[s]++;
            target += s;
        }
        target /= (skill.size() / 2);
        long long ans = 0;
        for(auto [x, y]: m){
            if(x != target - x){
                if(y != m[target - x]){
                    return -1;
                }
                ans += x * (target - x) * y;
                m.erase(target - x);
            }
            else{
                if(y % 2 != 0){
                    return -1;
                }
                ans += x * x * y / 2;
            }
        }
        return ans;
    }
};