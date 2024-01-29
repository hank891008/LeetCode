class Solution {
public:
    int to_digit(int n){
        int sum = 0;
        while(n != 0){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        map<int, int> m;
        int maxx = 0;
        for(int i = 1; i <= n; i++){
            m[to_digit(i)]++;
            maxx = max(maxx, m[to_digit(i)]);
        }
        int ans = 0;
        for(auto it: m){
            if(it.second == maxx){
                ans++;
            }
        }
        return ans;
    }
};