class Solution {
public:
    int minimumMoves(string s) {
        int cnt = 0;
        for(int i = 0; i < s.size();){
            if(s[i] == 'X'){
                cnt++;
                i += 3;
            }
            else{
                i += 1;
            }
        }
        return cnt;
    }
};