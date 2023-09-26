#include <iostream>
#include <cmath>

class Child{
public:
    double x; //------member variables declaration
    double y;
    Child *next;

    Child(double x_coord, double y_coord):x(x_coord), y(y_coord),next(nullptr){

    }

    void move_to_wolf(double t){
        if(t>=0){
            x-= t*cos(atan2(y, x));
            y-= t*sin(atan2(y, x)); 
        }
        
    }

    double distance_to_wolf(){
        double distance{};
        distance=sqrt(x*x+y*y);
        return distance;
    }
    
};
