/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int l = 1, r = n;
        while (l < r && r - l > 32) {
            int mid = l + (r - l) / 2;
            int res = guess(mid);
            if (res > 0) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        for (int i = l; i <= r; ++i) {
            if (guess(i) == 0) {
                return i;
            }
        }
        return -1;
    }
};