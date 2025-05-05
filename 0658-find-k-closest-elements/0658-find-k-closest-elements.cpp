class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        if(arr.size() == k){
            return arr;
        }
        vector<int> ans;
        int idx = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
        if(idx == 0){
            for(int i = 0; i < k; i++){
                ans.emplace_back(arr[i]);
            }
        }
        if(idx == arr.size()){
            for(int i = arr.size() - k; i < arr.size(); i++){
                ans.emplace_back(arr[i]);
            }
        }
        int l = idx - 1, r = idx;
        while(ans.size() < k && l >= 0 && r < arr.size()){
            int dis1 = abs(arr[l] - x), dis2 = abs(arr[r] - x);
            if(dis1 <= dis2){
                ans.emplace_back(arr[l--]);
            }
            else{
                ans.emplace_back(arr[r++]);
            }
        }
        while(ans.size() < k){
            if(l <= 0){
                ans.emplace_back(arr[r++]);
            }
            if(r >= arr.size()){
                ans.emplace_back(arr[l--]);
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};