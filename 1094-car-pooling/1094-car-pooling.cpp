class Solution {
public:
    struct Item{
        int passengers, from, to;
        Item(int passengers, int from, int to):passengers(passengers), from(from), to(to){}
        bool operator<(const Item &rhs)const{
            return from > rhs.from || (from == rhs.from && to > rhs.to);
        }
    };
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int curr = 0;
        priority_queue<Item> pq;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> in_car;  // to, passengers
        for(auto trip: trips) {
            pq.push(Item(trip[0], trip[1], trip[2]));
        }
        while(!pq.empty()) {
            Item now = pq.top();    pq.pop();
            // cout << now.passengers << ' ' << now.from << ' ' << now.to << '\n';
            while(!in_car.empty()) {
                auto in_car_top = in_car.top();
                if(in_car_top.first <= now.from) {
                    curr -= in_car_top.second;
                    in_car.pop();
                } else {
                    break;
                }
            }
            if(curr + now.passengers > capacity) {
                return false;
            }
            curr += now.passengers;
            in_car.emplace(now.to, now.passengers);
        }
        return true;
    }
};