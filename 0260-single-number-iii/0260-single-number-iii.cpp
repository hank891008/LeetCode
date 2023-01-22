class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        set<int>s;
        for(int i = 0; i < nums.size(); i++){
            if(s.count(nums[i])){
                s.erase(nums[i]);
            }
            else{
                s.insert(nums[i]);
            }
        }
        vector<int>v;
        for(auto it: s){
            v.emplace_back(it);
        }
        return v;
    }
};