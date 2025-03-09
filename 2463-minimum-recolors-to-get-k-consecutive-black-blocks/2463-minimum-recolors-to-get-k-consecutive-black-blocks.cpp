class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int cnt = 0;
        int ans = 0;
        for(int i = 0; i < blocks.size(); i++){
            if(i < k){
                cnt += (blocks[i] == 'W');
                ans = cnt;
            }
            else{
                cnt = cnt - (blocks[i - k] == 'W') + (blocks[i] == 'W');
                ans = min(ans, cnt);
            }
        }
        return ans;
    }
};