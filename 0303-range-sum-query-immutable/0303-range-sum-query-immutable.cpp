class NumArray {
public:
    int n;
    int BIT[(int)1e5 + 5];
    int lowbit(int x){
            return x & (-x);
        }
    void update(int idx, int val){
        while(idx < n){
            BIT[idx] += val;
            idx += lowbit(idx);
        }
    }
    int query(int idx){
        int sum = 0;
        while(idx > 0){
            sum += BIT[idx];
            idx -= lowbit(idx);
        }
        return sum;
    }
    
    NumArray(vector<int>& nums) {
        memset(BIT, 0, sizeof(BIT));
        n = nums.size() + 5;
        for(int i = 0; i < nums.size(); i++){
            update(i + 1, nums[i]);
        }
    }
    
    int sumRange(int left, int right) {
        return query(right + 1) - query(left);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */