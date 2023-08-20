class Solution {
public:
    int find(vector<int>& arr, int m, int target){
        int tot = 0;
        for(auto i: arr){
            tot += min(i, m);
        }
        return abs(tot - target);
    }
    int findBestValue(vector<int>& arr, int target) {
        int l = 0;
        int r = *max_element(arr.begin(), arr.end());
        while(l < r){
            int m = l + (r - l) / 2;
            if(find(arr, m, target) <= find(arr, m + 1, target)){
                r = m;
            }
            else{
                l = m + 1; 
            }
        }
        return l;
    }
};