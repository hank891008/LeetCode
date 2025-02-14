class Solution {
public:
    unordered_set<int> used;
    bool dfs(vector<int>& arr, int now){
        if(arr[now] == 0){
            return true;
        }
        used.insert(now);
        bool ans = false;;
        if(now - arr[now] >= 0 && !used.count(now - arr[now])){
            ans |= dfs(arr, now - arr[now]);
        }
        if(now + arr[now] < arr.size() && !used.count(now + arr[now])){
            ans |= dfs(arr, now + arr[now]);
        }
        return ans;
    }
    bool canReach(vector<int>& arr, int start) {
        return dfs(arr, start);
    }
};