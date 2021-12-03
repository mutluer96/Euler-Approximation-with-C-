#include<iostream>
#include<cmath>

using namespace std;

double eulerApproximation(double t_initial, double y_initial, double stepsize, double t_goal)
{
	double buffery, bufferResult, buffert;
	
	if (t_goal == t_initial)
	{
		return y_initial;
	}
	else if (t_goal > t_initial)
	{
		buffery = y_initial;
		buffert = t_initial;
		while (abs(t_goal - buffert) > stepsize)
		{
			bufferResult = buffery + stepsize * (1 + buffert - buffery);
			buffery = bufferResult;
			buffert = buffert + stepsize;
		}
		return bufferResult;
	}
	else
	{
		buffery = y_initial;
		buffert = t_initial;
		while (abs(t_goal - buffert) > stepsize)
		{
			bufferResult = buffery - stepsize * (1 + buffert - buffery);
			buffery = bufferResult;
			buffert = buffert - stepsize;
		}
		return bufferResult;
	}
}

int main()
{
	cout << "This Program Solves dy/dt=1+t-y(t) Numerically With Euler Method" << endl;
	double initialt, initialy, goalt, stepsize;
	cout << "Please enter initial contidion's t element\n";
	cin >> initialt;
	cout << "Please enter initial contidion's y element\n";
	cin >> initialy;
	cout << "Which t value do you want to solve the y for?\n";
	cin >> goalt;
	cout << "Please insert the step size\n";
	cin >> stepsize;
	cout << "The solution is equal to " << eulerApproximation(initialt, initialy, stepsize, goalt) << " \n\n";

	system("Pause");
	return 0;
}