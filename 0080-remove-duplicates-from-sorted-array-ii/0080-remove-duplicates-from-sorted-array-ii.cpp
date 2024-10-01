class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt = 0, prev = -1, move = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == prev){
                cnt++;
            }
            else{
                cnt = 1;
                prev= nums[i];
            }
            if(cnt > 2){
                move++;
            }
            nums[i - move] = nums[i];
        }
        return nums.size() - move;
    }
};