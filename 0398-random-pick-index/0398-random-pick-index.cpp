class Solution {
private:
    vector<int>v;
public:
    Solution(vector<int>& nums) {
        v = nums;
        srand(time(NULL));
    }
    
    int pick(int target) {
        int cnt = 1;
        int ret;
        for(int i = 0; i < v.size(); i++){
            if(v[i] == target){
                float r = (float)random() / RAND_MAX;
                if(r < 1.0 / cnt){
                    ret = i;
                }
                cnt++;
            }
        }
        return ret;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */