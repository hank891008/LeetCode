class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        unordered_set<int> s;
        for(auto num: nums){
            s.insert(stoi(num, nullptr, 2));
        }
        int ans = stoi(nums[0], nullptr, 2);
        int n = nums.size();
        while(s.count(ans)){
            ans = rand() % (int)pow(2, n);
        }
        return bitset<16>(ans).to_string().substr(16 - n);
    }
};