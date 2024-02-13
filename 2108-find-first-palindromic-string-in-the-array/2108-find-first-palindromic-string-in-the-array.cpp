class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(auto w: words){
            int n = w.size();
            bool is_p = true;
            for(int i = 0; i < n; i++){
                if(w[i] != w[n - 1 - i]){
                    is_p = false;
                    break;
                }
            }
            if(is_p){
                return w;
            }
        }
        return "";
    }
};