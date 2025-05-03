class Solution {
public:
    pair<int, int> solve(vector<int>& a, vector<int>& b){
        int cnt1 = 0, cnt2 = 1;
        for(int i = 1; i < a.size(); i++){
            if(cnt1 != INT_MAX && a[i] != a[0]){
                if(b[i] == a[0]){
                    cnt1++;
                }
                else{
                    cnt1 = INT_MAX;
                }
            }
            if(cnt2 != INT_MAX && a[i] != b[0]){
                if(b[i] == b[0]){
                    cnt2++;
                }
                else{
                    cnt2 = INT_MAX;
                }
            }
        }
        return {cnt1, cnt2};
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int ans = INT_MAX;
        auto [cnt1, cnt2] = solve(tops, bottoms);
        auto [cnt3, cnt4] = solve(bottoms, tops);
        ans = min({ans, cnt1, cnt2, cnt3, cnt4});

        return ans == INT_MAX ? -1 : ans;
    }
};