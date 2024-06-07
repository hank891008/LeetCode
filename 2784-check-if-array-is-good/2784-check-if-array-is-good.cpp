class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        map<int, int> m;
        for(int i = 1; i < n; i++){
            m[i]++;
        }
        m[n - 1]++;
        for(auto num: nums){
            if(!m.count(num)){
                return false;
            }
            m[num]--;
            if(m[num] == 0){
                m.erase(num);
            }
        }
        return m.empty();
    }
};