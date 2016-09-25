#include <iostream>
#include "Sensor.cpp"
using namespace std;

int main()
{   float var;
    float mean;
    Sensor <float> s;
    mean = s.getMean();
    var = s.getVar();

    cout << "The mean is" << endl;
    cout << mean<< endl;
    cout << "The variance is" << endl;
    cout << var<< endl;
    return 0;
}
