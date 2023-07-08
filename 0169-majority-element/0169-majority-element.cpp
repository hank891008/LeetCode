class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0], cnt = 1;
        for(int i = 1; i < nums.size(); i++){
            if(cnt == 0){
                major = nums[i];
                cnt++;
            }
            else if(nums[i] == major){
                cnt++;
            }
            else{
                cnt--;
            }
        }
        return major;
    }
};