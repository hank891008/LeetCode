class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> shifting(s.size() + 1, 0);
        for(auto shift: shifts){
            int start = shift[0], end = shift[1], dir = (shift[2] == 1 ? 1 : -1);
            shifting[start] += dir;
            shifting[end + 1] -= dir;
        }
        int now = 0;
        for(int i = 0; i < s.size(); i++){
            now = (now + shifting[i]) % 26;
            if(now < 0){
                now += 26;
            }
            s[i] = ((s[i] - 'a' + 26) + now) % 26 + 'a'; 
        }
        return s;
    }
};