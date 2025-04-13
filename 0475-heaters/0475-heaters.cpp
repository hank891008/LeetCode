class Solution {
public:
    bool check(vector<int>& houses, vector<int>& heaters, int rad){
        int i = 0, j = 0, n = houses.size(), m = heaters.size();
        while(i < n && j < m){
            while(i < n && houses[i] <= heaters[j] + rad && houses[i] >= heaters[j] - rad){
                i++;
            }
            j++;
        }
        return i == n;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = 1e9 + 5;
        while(l < r){
            int m = l + (r - l) / 2;
            if(check(houses, heaters, m)){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};