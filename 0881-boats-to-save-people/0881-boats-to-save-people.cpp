class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        int l = 0, r = people.size() - 1;
        while(l <= r){
            if(people[l] + people[r] <= limit){
                ans++;
                l++;
                r--;
            }
            else{
                ans++;
                r--;
            }

        }
        return ans;
    }
};