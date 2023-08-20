class Solution {
public:
    int maxScore(string s) {
        int maxx = 0;
        for(int i = 1; i < s.size(); i++){
            int j = 0;
            int now = 0;
            while(j < i){
                now += (s[j++] == '0');
            }
            while(j < s.size()){
                now += (s[j++] == '1');
            }
            maxx = max(maxx, now);
        }
        return maxx;
    }
};