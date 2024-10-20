class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        map<vector<int>, long long> m;
        long long ans = 0;
        for(auto rec: rectangles){
            int gcd = __gcd(rec[0], rec[1]);
            rec[0] /= gcd;
            rec[1] /= gcd;
            if(m.count(rec)){
                ans += (m[rec]);
            }
            m[rec]++;
        }
        return ans;
    }
};