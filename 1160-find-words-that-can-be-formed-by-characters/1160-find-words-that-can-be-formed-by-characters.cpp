class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char, int> m;
        for(auto ch: chars){
            m[ch]++;
        }
        int ans = 0;
        for(auto word: words){
            auto tmp_m = m;
            bool flag = true;
            for(auto w: word){
                if(tmp_m.count(w) && tmp_m[w] != 0){
                    tmp_m[w]--;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                ans += word.size();
            }
        }
        return ans;
    }
};