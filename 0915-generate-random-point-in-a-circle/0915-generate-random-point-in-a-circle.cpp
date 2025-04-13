class Solution {
public:
    default_random_engine gen;
    uniform_real_distribution<double> dist;
    double r, x, y;
    Solution(double radius, double x_center, double y_center):r(radius), x(x_center), y(y_center), dist(-radius, radius){}
    vector<double> randPoint() {
        while(true){
            double _x = dist(gen), _y = dist(gen);
            if(pow(_x, 2) + pow(_y, 2) <= pow(r, 2)){
                return {x + _x, y + _y};
            }
        }
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */