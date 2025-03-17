class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_set<int> s;
        for(auto num: nums){
            if(s.count(num)){
                s.erase(num);
            }
            else{
                s.insert(num);
            }
        }
        return s.size() == 0; 
    }
};