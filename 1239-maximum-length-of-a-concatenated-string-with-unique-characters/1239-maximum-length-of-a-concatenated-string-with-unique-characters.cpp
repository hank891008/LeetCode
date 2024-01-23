class Solution {
public:
    vector<string>now;
    int used[30];
    int ans;
    int check(){
        bool alpha[30] = {0};
        int tot = 0;
        for(auto st: now){
            for(auto s: st){
                if(alpha[s - 'a'] == true){
                    return -1;
                }
                alpha[s - 'a'] = true;
                tot++;
            }
        }
        return tot;
    }
    int maxLength(vector<string>& arr) {
        for(int i = 0; i < (1 << arr.size()); i++){
            now.clear();
            for(int j = 0; j < arr.size(); j++){
                if((i >> j) & 1){
                    now.emplace_back(arr[j]);
                }
            }
            ans = max(ans, check());
        }
        return ans;
    }
};