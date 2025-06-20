class Solution {
public:
    int maxDistance(string s, int k) {
        int n = s.size();
        int ans = 0;
        int x = 0, y = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'N'){
                y++;
            }
            else if(s[i] == 'S'){
                y--;
            }
            else if(s[i] == 'E'){
                x++;
            }
            else{
                x--;
            }
            ans = max(ans, min(abs(x) + abs(y) + 2 * k, i + 1));
        }
        return ans;
        
    }
};