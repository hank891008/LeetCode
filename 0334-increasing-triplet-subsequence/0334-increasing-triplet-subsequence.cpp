class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int i = INT_MAX, j = INT_MAX;
        for(auto num: nums){
            if(i > num){
                i = num;
            }
            else if(j > num && num > i){
                j = num;
            }
            else if(i < j && j < num){
                return true;
            }
        }
        return false;
    }
};