#ifndef PID_CONTROLLER_H
#define PID_CONTROLLER_H

class PIDController
{
private:
	//The gain values to be used in the PID controller
	double Kp;//The proportional gain value
	double Ki;//The integral gain value
	double Kd;//The derivative gain value
	
	double desiredLoc;//the position the motor should be at
	double integral;//The cumulative integral value
	double lastError;//The last error value, used to calculate the derivative
	
public:
	PIDController(double proportionalGain, double integralGain, double derivativeGain);
	~PIDController();
	
	void SetDesiredLoc(double loc);
	
	//This function will perform the PID calculations and return the suggested speed for the motor based on how far away it is from the desired location
	double CalculateOutput(double currentLoc);
};

#endif