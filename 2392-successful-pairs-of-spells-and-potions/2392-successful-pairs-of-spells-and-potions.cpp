class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++){
            long long minn = ceil(1. * success / spells[i]);
            int idx = (lower_bound(potions.begin(), potions.end(), minn) - potions.begin());
            spells[i] = potions.size() - idx;
        }
        return spells;
    }
};