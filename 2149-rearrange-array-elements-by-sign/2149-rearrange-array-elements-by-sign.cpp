class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        queue<int> p;
        queue<int> n;
        vector<int> ans;
        for(auto num: nums){
            if(num > 0){
                p.emplace(num);
            }
            else{
                n.emplace(num);
            }
        }
        for(int i = 0; i < nums.size() / 2; i++){
            ans.emplace_back(p.front());
            ans.emplace_back(n.front());
            p.pop();
            n.pop();
        }
        return ans;
    }
};