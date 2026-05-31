class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long m = mass;
        sort(asteroids.begin(), asteroids.end());
        for(auto a: asteroids) {
            if(m >= a) {
                m += a;
            } else {
                return false;
            }
        }
        return true;
    }
};