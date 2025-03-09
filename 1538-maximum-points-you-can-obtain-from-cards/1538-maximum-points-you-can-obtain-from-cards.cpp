class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        for(int i = 1; i < n; i++){
            cardPoints[i] += cardPoints[i - 1];
        }
        if(n == k){
            return cardPoints[n - 1];
        }
        for(int i = 0; i < n; i++){
            cout << cardPoints[i] << ' ';
        }
        int ans = max(cardPoints[k - 1], cardPoints[n - 1] - cardPoints[n - k - 1]);
        for(int i = 1; i < k + 1; i++){ // i + n - k - 1 < n -> k + 1
            ans = max(ans, cardPoints[n - 1] - cardPoints[i + n - k - 1] + cardPoints[i - 1]);
        }
        return ans;
    }
};