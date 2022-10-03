class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans = 0;
        int len = 1;
        int maxx = neededTime[0];
        int tot = neededTime[0];
        for(int i = 1; i < colors.size(); i++){
            if(colors[i] == colors[i - 1]){
                len++;
                tot += neededTime[i];
                maxx = max(maxx, neededTime[i]);
            }
            else{
                //cout << i << ' ';
                if(len == 1) {
                    len = 1;
                }
                else {
                    ans += tot - maxx;
                    tot = neededTime[i];
                }
                tot = neededTime[i];
                maxx = neededTime[i];
                len = 1;
           }
            cout << ans << '\n';
        }
        if(len != 1){
            ans += tot - maxx;
        }
        return ans;
    }
};