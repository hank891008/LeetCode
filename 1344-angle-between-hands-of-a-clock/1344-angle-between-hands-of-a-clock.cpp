class Solution {
public:
    double angleClock(int hour, int minutes) {
        double a = (hour % 12 * 30) + minutes / 2.;
        double b = minutes * 6;
        return min(abs(a - b), 360 - abs(a - b));
    }
};