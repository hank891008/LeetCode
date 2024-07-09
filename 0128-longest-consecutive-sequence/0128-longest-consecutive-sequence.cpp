class Solution {
public:
    unordered_map<int, int> fa;
    int findr(int x){
        if(!fa.count(x)){
            return -1;
        }
        return x == fa[x] ? fa[x] : fa[x] = findr(fa[x]);
    }
    void unite(int x){
        if(findr(x - 1) != -1){
            fa[findr(x - 1)] = findr(x);
        }
        if(findr(x + 1) != -1){
            fa[findr(x + 1)] = findr(x);
        }
    }
    int longestConsecutive(vector<int>& nums) {
        for(auto num: nums){
            fa[num] = num;
        }
        for(auto num: nums){
            unite(num);
        }
        unordered_map<int, int> cnt;
        for(auto [_, y]: fa){
            cnt[findr(y)]++;
        }
        int ans = 0;
        for(auto [_, c]: cnt){
            ans = max(ans, c);
        }
        return ans;
        
    }
};