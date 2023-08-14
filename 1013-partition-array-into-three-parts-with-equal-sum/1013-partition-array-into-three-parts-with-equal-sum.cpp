class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int avg = accumulate(arr.begin(), arr.end(), 0);
        if(avg % 3 != 0){
            return false;
        }
        avg /= 3;
        int tot = 0;
        int cnt = 0;
        for(int num: arr){
            tot += num;
            if(tot == avg){
                tot = 0;
                cnt++;
            }
        }
        // cout << cnt << ' ' << tot << '\n';
        return cnt >= 3;
    }
};