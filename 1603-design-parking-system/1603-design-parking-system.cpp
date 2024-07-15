class ParkingSystem {
public:
    int a, b, c;
    int curr_a, curr_b, curr_c;
    ParkingSystem(int big, int medium, int small) {
        a = big, b = medium, c = small;
        curr_a = curr_b = curr_c = 0;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            return ++curr_a <= a;
        }
        else if(carType == 2){
            return ++curr_b <= b;
        }
        else{
            return ++curr_c <= c;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */