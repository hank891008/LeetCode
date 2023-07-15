class Solution {
public:
    int jump(vector<int>& nums) {
        int jump[(int)nums.size()];
        for(int i = 0; i < nums.size(); i++){
            jump[i] = 0x3f3f3f3f;
        }
        jump[0] = 0;
        for(int i = 0; i < nums.size(); i++){
            for(int j = 1; j <= nums[i]; j++){
                if(i + j >= nums.size()){
                    break;
                }
                jump[i + j] = min(jump[i] + 1, jump[i + j]);
            }
        }
        return jump[(int)nums.size() - 1];
    }
};