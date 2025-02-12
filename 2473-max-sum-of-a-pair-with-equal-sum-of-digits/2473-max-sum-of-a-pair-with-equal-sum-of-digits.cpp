class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> m;
        int maxx = -1;
        for(auto num: nums){
            string str_num = to_string(num);
            int digit = accumulate(str_num.begin(), str_num.end(), -('0' * str_num.size()));
            if(!m.count(digit)){
                m[digit] = num;
            }
            else{
                maxx = max(maxx, m[digit] + num);
                m[digit] = max(m[digit], num);
            }
        }
        return maxx;
    }
};