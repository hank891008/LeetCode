class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int>colored(n + 5, 0);
        vector<int>ans;
        int cnt = 0;
        for(auto q: queries){
            int idx = q[0] + 1, color = q[1];
            if(colored[idx - 1] != 0){
                if(colored[idx - 1] == colored[idx]){
                    cnt--;
                }
                if(colored[idx - 1] == color){
                    cnt++;
                }
            }
            if(colored[idx + 1] != 0){
                if(colored[idx + 1] == colored[idx]){
                    cnt--;
                }
                if(colored[idx + 1] == color){
                    cnt++;
                }
            }
            ans.emplace_back(cnt);
            colored[idx] = color;
        }
        return ans;
    }
};