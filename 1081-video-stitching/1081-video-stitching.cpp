class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end(), [&](vector<int>& a, vector<int>& b){
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        if(clips[0][0] > 0){
            return -1;
        }
        if(clips[0][1] >= time){
            return 1;
        }
        int cnt = 1;
        int now = clips[0][1], maxx = 0;
        int idx = 1;
        while(idx < clips.size()){
            if(clips[idx][0] <= now){
                maxx = max(maxx, clips[idx][1]);
                if(maxx >= time){
                    return cnt + 1;
                }
                idx++;
            }
            else{
                if(maxx == 0){
                    return -1;
                }
                cnt++;
                now = maxx;
                maxx = 0;
            }
        }
        if(maxx < time){
            return -1;
        }
        return cnt + 1;
    }
};