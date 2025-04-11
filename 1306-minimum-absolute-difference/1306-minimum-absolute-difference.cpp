class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        ans.push_back({arr[0], arr[1]});
        for(int i = 2; i < arr.size(); i++){
            if(arr[i] - arr[i - 1] < ans.back()[1] - ans.back()[0]){
                ans.clear();
                ans.push_back({arr[i - 1], arr[i]});
            }
            else if(arr[i] - arr[i - 1] == ans.back()[1] - ans.back()[0]){
                ans.push_back({arr[i - 1], arr[i]});
            }
        }
        return ans;
    }
};