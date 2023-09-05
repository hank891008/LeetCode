class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int>s;
        for(auto num: nums){
            if(s.count(num)){
                return num;
            }
            s.insert(num);
        }
        return -1;
    }
};