class Solution {
public:
    int check(vector<int>& piles, int m){
        int tot = 0;
        for(int i = 0; i < piles.size(); i++){
            tot += ceil((double)piles[i] / m);
        }
        return tot;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = *max_element(piles.begin(), piles.end());
        while(l < r){
            int m = l + (r - l) / 2;
            if(check(piles, m) > h){
                l = m + 1;
            }
            else{
                r = m;
            }
        }
        return l;
    }
};