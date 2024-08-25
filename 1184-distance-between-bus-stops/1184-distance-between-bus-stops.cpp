class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        if(destination < start){
            swap(destination, start);
        }
        int tot = accumulate(distance.begin(), distance.end(), 0);
        int sub_tot = accumulate(distance.begin() + start, distance.begin() + destination, 0);
        return min(sub_tot, tot - sub_tot);
    }
};