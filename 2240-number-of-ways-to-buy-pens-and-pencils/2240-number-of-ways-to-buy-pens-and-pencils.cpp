class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long ans = 0;
        long long pen = 0;
        while(cost1 * pen <= total){
            ans += ((total - cost1 * pen) / cost2 + 1);
            pen++;
        }
        return ans;
    }
};