class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        int n = energy.size();
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(initialEnergy <= energy[i]){
                int needed = energy[i] - initialEnergy + 1;
                initialEnergy += needed;
                ans += needed;
            }
            if(initialExperience <= experience[i]){
                int needed = experience[i] - initialExperience + 1;
                initialExperience += needed;
                ans += needed;
            }
            initialEnergy -= energy[i];
            initialExperience += experience[i];
        }
        return ans;
    }
};