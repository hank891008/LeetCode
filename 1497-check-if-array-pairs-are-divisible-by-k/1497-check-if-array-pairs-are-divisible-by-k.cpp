class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> mod(k, 0);
        for(int i = 0; i < n; i++){
            mod[(arr[i] % k + k) % k]++;
        }
        for(int i = 1; i <= k / 2; i++){
            if(mod[i] != mod[k - i]){
                return false;
            }
        }
        return mod[0] % 2 == 0;
    }
};