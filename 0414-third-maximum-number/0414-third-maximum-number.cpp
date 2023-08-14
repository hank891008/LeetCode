class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long one = LLONG_MIN, two = LLONG_MIN, three = LLONG_MIN;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == one || nums[i] == two || nums[i] == three){
                continue;
            }
            if(nums[i] > one){
                three = two;
                two = one;
                one = nums[i];
            }
            else if(nums[i] > two){
                three = two;
                two = nums[i];
            }
            else if(nums[i] > three){
                three = nums[i];
            }
        }
        if(three == LLONG_MIN){
            three = one;
        }
        return three;
    }
};