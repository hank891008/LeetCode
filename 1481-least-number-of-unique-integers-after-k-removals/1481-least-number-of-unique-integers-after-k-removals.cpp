class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> m;
        for(auto num: arr){
            m[num]++;
        }
        vector<int> ans;
        for(auto it: m){
            ans.emplace_back(it.second);
        }
        sort(ans.begin(), ans.end());
        int tot = 0;
        for(int i = 0; i < ans.size(); i++){
            tot += ans[i];
            if(tot > k){
                return ans.size() - i;
            }
            else if(tot == k){
                return ans.size() - i - 1;
            }
        }
        return -1;
    }
};