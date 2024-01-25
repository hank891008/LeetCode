class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < moves.size(); i++){
            if(moves[i] == 'L'){
                ans--;
            }
            else if(moves[i] == 'R'){
                ans++;
            }
            else{
                cnt++;
            }
        }
        return abs(ans) + cnt;
    }
};