class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        for(int i = 0; i < s.size() / 2; i++){
            if(s.size() % (i + 1) == 0){
                bool flag = true;
                for(int j = i + 1; j < s.size(); j++){
                    if(s[j] != s[j % (i + 1)]){
                        flag = false;
                        break;
                    }
                }
                if(flag){
                    return true;
                }
            }
        }
        return false;
    }
};