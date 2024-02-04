class UndergroundSystem {
public:
    map<int, pair<string, int>> chk_record;
    map<pair<string, string>, pair<int, int>> all_record;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        chk_record[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto record = chk_record[id];
        pair<string, string> stations = {record.first, stationName};
        int time_diff = t - record.second;
        all_record[stations].first += time_diff;
        all_record[stations].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string, string> stations = {startStation, endStation};
        return (double)all_record[stations].first / all_record[stations].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */