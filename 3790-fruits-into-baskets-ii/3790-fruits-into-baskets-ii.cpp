class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        for(auto f: fruits){
            int placed = 1;
            for(int i = 0; i < baskets.size(); i++){
                if(f <= baskets[i]){
                    baskets[i] = 0;
                    placed = 0;
                    break;
                }
            }
            cnt += placed;
        }
        return cnt;
    }
};