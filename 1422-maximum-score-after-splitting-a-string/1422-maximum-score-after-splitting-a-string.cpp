class Solution {
public:
    int maxScore(string s) {
        int maxx = 0;
        int ones = 0, zeros = 0;
        for(auto i: s){
            ones += (i == '1');
        }
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == '0'){
                zeros++;
            }
            else{
                ones--;
            }
            maxx = max(maxx, zeros + ones);
        }
        return maxx;
    }
};