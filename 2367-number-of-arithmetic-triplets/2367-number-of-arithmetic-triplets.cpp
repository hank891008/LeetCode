class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[j] - nums[i] == diff){
                    for(int k = j + 1; k < n; k++){
                        if(nums[k] - nums[j] == diff){
                            ans++;
                        }
                        else if(nums[k] - nums[j] > diff){
                            break;
                        }
                    }
                }
                else if(nums[j] - nums[i] > diff){
                    break;
                }
            }
        }
        return ans;
    }
};