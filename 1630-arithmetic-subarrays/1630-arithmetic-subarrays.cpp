class Solution {
public:
    bool check(vector<int>& nums, int l, int r){
        int minn = *min_element(nums.begin() + l, nums.begin() + r + 1);
        int maxx = *max_element(nums.begin() + l, nums.begin() + r + 1);
        if(maxx == minn){
            for(int i = l; i <= r; i++){
                if(nums[i] != minn){
                    return false;
                }
            }
            return true;
        }
        int k = r - l;
        cout << minn << ' ' << maxx << ' ' << k << '\n';
        if((maxx - minn) % k != 0){
            return false;
        }
        set<int> s;
        int curr = minn, interval = (maxx - minn) / k;
        for(int i = l; i <= r; i++){
            s.insert(curr);
            curr += interval;
        }
        for(int i = l; i <= r; i++){
            if(!s.count(nums[i])){
                return false;
            }
            s.erase(nums[i]);
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0; i < l.size(); i++){
            ans.emplace_back(check(nums, l[i], r[i]));
        }
        return ans;
    }
};