class Solution {
public:
    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> prefix_Y(n), prefix_N(n);
        
        prefix_Y[0] = customers[0] == 'Y';
        prefix_N[0] = customers[0] == 'N';
        
        for (int i = 1; i < n; i++) {
            prefix_Y[i] = prefix_Y[i-1] + (customers[i] == 'Y');
            prefix_N[i] = prefix_N[i-1] + (customers[i] == 'N');
        }

        int minCost = prefix_Y.back();
        int bestHour = 0;

        for (int i = 1; i <= n; i++) {
            int cost = prefix_N[i-1] + (prefix_Y.back() - prefix_Y[i-1]);
            if (cost < minCost) {
                minCost = cost;
                bestHour = i;
            }
        }

        return bestHour;
    }
};
