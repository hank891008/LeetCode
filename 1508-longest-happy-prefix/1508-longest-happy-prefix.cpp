class Solution {
public:
    string longestPrefix(string s) {
        vector<int> next(s.size(), 0);
        int i = 1, prefix_len = 0;
        while(i < s.size()){
            if(s[i] == s[prefix_len]){
                prefix_len++;
                next[i] = prefix_len;
                i++;
            }
            else{
                if(prefix_len != 0){
                    prefix_len = next[prefix_len - 1];
                }
                else{
                    next[i] = 0;
                    i++;
                }
            }
        }
        return s.substr(0, next.back());
    }
};