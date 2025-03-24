class Solution {
public:
    int addMinimum(string word) {
        int i = 0, ans = 0;
        while(i < word.size()){
            if(word.substr(i, 3) == "abc"){
                i += 3;
            }
            else if(word.substr(i, 2) == "ab" || word.substr(i, 2) == "ac" || word.substr(i, 2) == "bc"){
                i += 2;
                ans += 1;
            }
            else{
                i += 1;
                ans += 2;
            }
        }
        return ans;
    }
};