class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int size = candyType.size();
        unordered_set<int> m(candyType.begin(), candyType.end());
        return min(size / 2, (int)m.size());
    }
};