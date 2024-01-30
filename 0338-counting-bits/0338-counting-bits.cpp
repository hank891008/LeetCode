class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1);
        int highest_pos = 0;
        int bit[32];
        memset(bit, 0, sizeof(bit));
        for(int i = 1; i <= n; i++){
            int carry = 1;
            int cnt = 0;
            for(int i = 0; i <= highest_pos; i++){
                bit[i] += carry;
                carry = 0;
                if(bit[i] > 1){
                    carry = 1;
                    bit[i] = 0;
                }
                else{
                    cnt += bit[i];
                }
            }
            if(carry == 1){
                highest_pos++;
                bit[highest_pos]++;
                cnt++;
            }
            ans[i] = cnt;
        }
        return ans;
    }
};