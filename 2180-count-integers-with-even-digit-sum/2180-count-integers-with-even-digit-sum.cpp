class Solution {
public:
    int countEven(int num) {
        vector<int>v;
        for(int i = 2; i <= 1000; i++){
            if((i / 1000 + i / 100 + i / 10 % 10 + i) % 2 == 0){
                v.emplace_back(i);
            }
        }
        return upper_bound(v.begin(), v.end(), num) - v.begin();
    }
};