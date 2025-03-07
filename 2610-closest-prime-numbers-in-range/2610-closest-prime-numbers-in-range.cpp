class Solution {
public:
    vector<int> getPrime(int upper){
        vector<int> p(upper + 1, 1);
        p[0] = p[1] = false;
        for(int i = 2; i * i <= upper; i++){
            if(p[i]){
                for(int j = i * i; j <= upper; j += i){
                    p[j] = 0;
                }
            }
        }
        return p;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> prime = getPrime(right);
        vector<int> p;
        for(int i = left; i <= right; i++){
            if(prime[i]){
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