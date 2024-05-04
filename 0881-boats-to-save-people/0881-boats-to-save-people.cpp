class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int ans = 0;
        int l = 0, r = people.size() - 1;
        while(l <= r && people[l] <= limit){
            if(people[l] + people[r] <= limit){
                ans++;
                l++;
                r--;
            }
            else if(people[r] <= limit){
                ans++;
                r--;
            }
            else{
                l++;
            }
        }
        return ans;
    }
};