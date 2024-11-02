class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        vector<int> arr;
        for(int i = 0; i < 3; i++){
            for(auto c: code){
                arr.emplace_back(c);
            }
        }
        vector<int> ans(code.size(), 0);
        if(k == 0){
            return ans;
        }
        for(int i = 0; i < code.size(); i++){
            int idx = i + code.size();
            if(k > 0){
                for(int j = 1; j <= k; j++){
                    ans[i] += arr[idx + j];
                }
            }
            else{
                for(int j = k; j < 0; j++){
                    ans[i] += arr[idx + j];
                }
            }
        }
        return ans;
    }
};