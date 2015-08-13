//Purpose: A function to compare floating point numbers. Numbers in computers
//are internally represented in binary, and there are some floating point
//numbers (such as 0.1) that do not have an exact representation in binary.
//If there is no exact representation in binary, then the value is rounded to
//the nearest representation in binary, which results in some floating point
//numbers being slightly imprecise. This imprecision results in some comparisons
//(such as testing for equality) to not work as expected. Here we implement a
//function that compares two floating point numbers by using an epsilon value
//(error margin) that takes into account floating point imprecision.
#include <iostream>
#include <algorithm>
#include <limits>
#include <math.h>
using namespace std;

#define EPSILON 0.00001

bool nearly_equal(float a, float b){
    float abs_a = fabs(a);
    float abs_b = fabs(b);
    float diff = fabs(a - b);

    if(a == b){
        return true;
    }
    //a or b is zero or both are extremely close to zero
    //other implementations use float min normal instead of float min
    else if(a == 0 || b == 0 || diff < std::numeric_limits<float>::min()){
        return diff < (EPSILON * std::numeric_limits<int>::min());
    }
    //use relative error
    else{
        return (diff / std::min((abs_a + abs_b), std::numeric_limits<float>::max())) < EPSILON;
    }
}

int main(){
    cout << nearly_equal(0, 0) << endl;
    cout << nearly_equal(0, 0.00001) << endl;
    float a = 0.2 + 0.1;
    float b = 0.15 + 0.15;
    cout << nearly_equal(a, b) << endl;
    return 0;
}
