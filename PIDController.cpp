#include "PIDController.h"

PIDController::PIDController(double proportionalGain, double integralGain, double derivativeGain)
{
	//Set the gain values
	Kp = proportionalGain;
	Ki = integralGain;
	Kd = derivativeGain;
	
	//Set setPoint, integral and lastError to zero
	setpoint = 0;
	integral = 0;
	lastError = 0;
}

void PIDController::NewSetpoint(double sp)
{
	//Set setPoint to the new desired location
	setpoint = sp;
	
	//Reset the integral and lastError values
	integral = 0;
	lastError = 0;
}

//Returns the suggested motor speed (-1 to 1 inclusive) obtained from the PID calculations
double PIDController::CalculateOutput(double currentLoc)
{
	double error;
	double derivative;
	double output;
	
	//Calculate the error
	error = setpoint - currentLoc;
	
	//Calculate the derivative
	derivative = (error - lastError)
	
	//Calculate the output
	output = (Kp * error) + (Ki * integral) + (Kd * derivative);
	
	//Keep the output in a range of [-1, 1]
	if(output > 1)
	{
		output = 1;
	}
	else if(output < -1)
	{
		output = -1
	}
	//There is no need to update the integral if the motor is already running at 100%
	else
	{
		integral += error;
	}
	
	//Update lastError
	lastError = error;
	
	//return the output
	return output;
}