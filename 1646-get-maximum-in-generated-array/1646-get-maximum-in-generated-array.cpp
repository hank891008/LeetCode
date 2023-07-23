class Solution {
public:
    int getMaximumGenerated(int n) {
        vector<int>num(n + 1);
        int ret = 0;
        for(int i = 0; i <= n; i++){
            if(i < 2){
                num[i] = i;
            }
            else{
                if(i % 2 == 0){
                    num[i] = num[i / 2];
                }
                else{
                    num[i] = num[i / 2] + num[i / 2 + 1];
                }
            }
            ret = max(ret, num[i]);
        }
        return ret;
    }
};