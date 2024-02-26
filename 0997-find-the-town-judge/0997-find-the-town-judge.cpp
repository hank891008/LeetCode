class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> ans(n, 0);
        unordered_set<int> s;
        for(auto v: trust){
            ans[v[1] - 1]++;
            s.insert(v[0] - 1);
        }
        int judge = -1;
        for(int i = 0; i < n; i++){\
            if(ans[i] == n - 1 && judge == -1 && !s.count(i)){
                judge = i + 1;
            }
            else if(ans[i] == n - 1){
                return -1;
            }
        }
        return judge;
    }
};