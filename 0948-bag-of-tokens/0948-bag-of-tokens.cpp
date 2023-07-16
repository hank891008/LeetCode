class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        int maxx = 0, now = 0;
        int l = 0, r = tokens.size() - 1;
        while(l <= r){
            if(power >= tokens[l]){
                power -= tokens[l++];
                now++;
            }
            else if(now > 0){
                power += tokens[r--];
                now--;
            }
            else{
                break;
            }
            maxx = max(maxx, now);
            cout << power << ' ' << now << '\n';
            cout << maxx << '\n';
        }
        return maxx;
    }
};