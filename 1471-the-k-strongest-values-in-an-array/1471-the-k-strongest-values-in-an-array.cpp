class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int m = arr[(arr.size() - 1) / 2];
        sort(arr.begin(), arr.end(), [&](int x, int y){
            return abs(x - m) > abs(y - m) || (abs(x - m) == abs(y - m) && x > y);
        });
        arr.resize(k);
        return arr;
    }
};