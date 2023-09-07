class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int>v(2 * nums.size());
        for(int i = 0; i < nums.size(); i++){
            v[i] = v[i + nums.size()] = nums[i];
        }
        return v;
    }
};