class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        auto it = s.rbegin();
        for(int i = 0; i < 2; i++){
            it++;
            if(it == s.rend()){
                return *s.rbegin();
            }
        }
        return *it;
    }
};