class Solution {
public:
    set<int>s;
    map<pair<int, int>, bool>used;
    bool dp(int now, int k){
        if(used.count({now, k})){
            return used[{now, k}];
        }
        bool ret = false;
        if(s.count(now)){
            if(now == *s.rbegin()){
                return true;
            }
            for(int i = max(k - 1, 1); i <= k + 1; i++){
                if(s.count(now + i)){
                    ret |= (used[{now + i, i}]) = dp(now + i, i);
                }
            }
        }
        return ret;
    }
    bool canCross(vector<int>& stones) {
        for(auto stone: stones){
            s.insert(stone);
        }
        return dp(0, 0);
    }
};