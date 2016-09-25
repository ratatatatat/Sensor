#include "Sensor.h"
#include <iostream>
using namespace std;

template<class T>
Sensor<T>::Sensor(){
}

template<class T>
void Sensor<T>::initVar(T thresh){
    var = 0.0;
    var_ = 0.0;
    mean = 0.0;
    mean_ = 0.0;
    n = 1.0;
    n_ = 0.0;
    setThresh(thresh);
}

template<class T>
void Sensor<T>::runningSum(){
    mean = ((mean_ * n_) + meas)/n;
}

template<class T>
void Sensor<T>::calcStat(T newMeas){
	//Calculates the first and second order statistics of the sensor measurement.
    //Initialize the variables to a value
    cout << "Inside calcStat" << endl;
    T threshdiff;
	setMeas(newMeas);
	runningSum();
	if(n>1){
        runningVar();
        threshdiff = var - var_;
    	if(threshdiff<threshold){
    		//This step should break the calcLoop.
    		statReady = true;
    	}
	}
    n_=n;
    n = n+1.0;
    mean_ = mean;
    var_ = var;
    cout << var << endl;
    cout << mean << endl;

}

template<class T>
void Sensor<T>::runningVar(){
	var  = ((n_ * var_)/n) + (1.0/n_)*(meas - mean_)*(meas - mean_);

}

template<class T>
T Sensor<T>::getMean(){
	return this->mean;
}

template<class T>
T Sensor<T>::getVar(){
	return this->var;
}

template<class T>
void Sensor<T>::setMeas(T newMeas){
	//Set the New Measurement internally.
	meas = newMeas;
}

// template<class T>
// void Sensor<T>::popDummyArray(int n){
// 	int j;
// 	int mod;
// 	for(j=0;j<n;j=j+1){
// 		mod = j % 2;
// 		if(mod==1){
// 			this->measArray[j]=1.0;
// 		}
// 		else{
// 			this->measArray[j]=-1.0;
// 		}
// 	}
// }

template<class T>
void Sensor<T>::setThresh(T thresh){
	//Set the threshold variable for class.
	threshold = thresh;
}
