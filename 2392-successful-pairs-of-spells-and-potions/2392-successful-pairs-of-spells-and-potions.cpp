class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        for(int i = 0; i < spells.size(); i++){
            long long minn = ceil(1. * success / spells[i]);
            spells[i] = distance(lower_bound(potions.begin(), potions.end(), minn), potions.end());
        }
        return spells;
    }
};