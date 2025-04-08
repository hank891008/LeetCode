class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); i += 3){
            s.clear();
            bool flag = true;
            for(int j = i; j < nums.size(); j++){
                if(s.count(nums[j])){
                    flag = false;
                    break;
                }
                s.insert(nums[j]);
            }
            if(flag){
                return i / 3;
            }
        }
        return ceil(nums.size() / 3.);
    }
};