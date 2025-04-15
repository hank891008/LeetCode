class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;
        while(true){
            bool flag = true;
            for(auto& num: nums){
                if(num & 1){
                    ans++;
                }
                num >>= 1;
                if(num){
                    flag = false;
                }
            }
            if(flag){
                break;
            }
            ans++;
        }
        return ans;
    }
};