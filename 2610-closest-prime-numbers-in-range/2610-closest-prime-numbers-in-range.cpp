class Solution {
public:
    bool isPrime(int x){
        if(x == 1){
            return false;
        }
        else if(x == 2){
            return true;
        }
        for(int i = 2; i <= sqrt(x); i++){
            if(x % i == 0){
                return false;
            }
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> p;
        for(int i = left; i <= right; i++){
            if(isPrime(i)){
                p.emplace_back(i);
            }
        }
        if(p.size() < 2){
            return {-1, -1};
        }
        vector<int> ans = {p[0], p[1]};
        for(int i = 2; i < p.size(); i++){
            if(p[i] - p[i - 1] < ans[1] - ans[0]){
                ans = {p[i - 1], p[i]};
            }
        }
        return ans;
    }
};