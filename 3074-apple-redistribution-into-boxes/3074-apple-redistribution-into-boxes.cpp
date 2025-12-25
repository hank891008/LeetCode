class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int tot = accumulate(apple.begin(), apple.end(), 0);
        sort(capacity.begin(), capacity.end(), greater<int>());
        for(int i = 0; i < capacity.size(); i++) {
            if(i > 0) {
                capacity[i] += capacity[i - 1];
            }
            if(capacity[i] >= tot) {
                return i + 1;
            }
        }
        return capacity.size();
    }
};