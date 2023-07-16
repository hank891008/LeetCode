class Solution {
public:
    bool isPrime(int x){
        if(x == 1){
            return false;
        }
        if(x == 2){
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
        vector<int>v;
        for(int i = left; i <= right; i++){
            if(isPrime(i)){
                v.emplace_back(i);
            }
        }
        vector<int>ans;
        if(v.size() < 2){
            ans.emplace_back(-1);
            ans.emplace_back(-1);
        }
        else{
            int minn = INT_MAX;
            for(int i = 1; i < v.size(); i++){
                if(v[i] - v[i - 1] < minn){
                    ans.clear();
                    minn = v[i] - v[i - 1];
                    ans.emplace_back(v[i - 1]);
                    ans.emplace_back(v[i]);
                }
            }
        }
        return ans;
    }
};