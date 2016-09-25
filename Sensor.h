#include <math.h>


#ifndef _Sensor_h_
#define _Sensor_h_

template<class T>
class Sensor{

	public:
			Sensor();//Does nothing anymore
			T getMean();//Public method to access the average function of measurements,
			T getVar();//Public method to access the variance
			void calcStat(T newMeas);//This will calculate the mean and variance iteratively. Call it from outside the object;
			bool statReady = false;
			void initVar(T thresh); //Re initialize the variables, run the functions for each axis. 

	private:
		T mean;//Mean n+1
		T mean_;//Mean n
		T meas; //New measurement
		T n;//Measurement Number n + 1
		T n_;//n
		T var; //variance n + 1
		T var_; // variance n
		T threshold; //The threshold, that determines if stat ready, ie var - var_ < Thresh, statready = true; Same for variance. 
		void runningSum();//The formula to calculate the running sum/mean, iterative step
		void runningVar();//The formula to calculate the running variance, iteratively
		void setMeas(T newMeas);//Set the measurement inside the class, updates the meas vairable. 
		void setThresh(T thresh);//Set the internal threshold
};	
#endif
