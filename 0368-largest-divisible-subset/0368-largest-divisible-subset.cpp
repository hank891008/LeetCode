class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> in_deg(n), prev(n, -1);
        vector<vector<int>> G(n);
        for(int i = 0 ; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[j] % nums[i] == 0){
                    G[j].emplace_back(i);
                    in_deg[i]++;
                }
            }
        }
        queue<int> q;
        for(int i = 0; i < n; i++){
            if(in_deg[i] == 0){
                q.emplace(i);
            }
        }
        int last;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v: G[u]){
                if(--in_deg[v] == 0){
                    q.emplace(v);
                    prev[v] = u;
                }
            }
            last = u;
        }
        vector<int> ans;
        for(int i = last; i != -1; i = prev[i]){
            ans.emplace_back(nums[i]);
        }
        return ans;
    }
};