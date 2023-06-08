#include<iostream>

using namespace std;

class ParkingSystem {
   
    public: 
    int bigNum,mediumNum,smallNum;
        ParkingSystem(int big, int medium, int small) {
            bigNum = big;
            mediumNum = medium;
            smallNum = small;
        }

        bool addCar(int carType) {
            if (carType == 1)
            {
                if (bigNum != 0)
                {
                    bigNum--;
                    return true;
                }

            } else if (carType == 2)
            {
                if (mediumNum != 0)
                {
                    mediumNum--;
                    return true;
                }

            }
            else if (carType == 3)
            {
                if (smallNum != 0)
                {
                    smallNum--;
                    return true;
                }
            }

            return false;
        }
             
};


int main() {

    ParkingSystem obj(1,1,0);

    cout << obj.addCar(1) << endl;
    cout << obj.addCar(2) << endl;
    cout << obj.addCar(3) << endl;
    cout << obj.addCar(1)<< endl;


    return 0;
}
