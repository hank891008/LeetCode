class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> prefix(arr.size() + 5, 0);
        
        prefix[1] = arr[0];
        for(int i = 1; i < arr.size(); i++){
            prefix[i + 1] = prefix[i] ^ arr[i];
        }
        vector<int> ans;
        for(auto q: queries){
            ans.emplace_back(prefix[q[1] + 1] ^ prefix[q[0]]);
        }
        return ans;
    }
};