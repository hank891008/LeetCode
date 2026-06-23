class Solution {
public:
    bool checkOnesSegment(string s) {
        bool flag = 0;
        for(auto ch: s) {
            if(ch == '0') {
                flag = 1;
            } else if(flag == 1) {
                return false;
            }
        }
        return true;
    }
};