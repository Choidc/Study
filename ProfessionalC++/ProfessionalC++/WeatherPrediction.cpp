#include <iostream>
#include <sstream>

#include "WeatherPrediction.h"

using namespace std;

WeatherPrediction::~WeatherPrediction ()
{}

void WeatherPrediction::setCurrentTempFahrenheit (int inTemp)
{
	mCurrentTempFahrenheit = inTemp;
}

void WeatherPrediction::setPositionOfJupiter (int inDistanceFromMars)
{
	mDistanceFromMars = inDistanceFromMars;
}

int WeatherPrediction::getTomorrowTempFahrenheit () const
{
	return (mDistanceFromMars / 1000) + mCurrentTempFahrenheit;
}

double WeatherPrediction::getChanceOfRain () const
{
	return 0.5;
}

void WeatherPrediction::showResult () const
{
	cout << "Result: " << (getChanceOfRain () * 100) << " chance."
		<< " Temp. " << getTomorrowTempFahrenheit () << endl;
}

std::string WeatherPrediction::getTemperature () const
{
	stringstream ss;
	ss << mCurrentTempFahrenheit;
	return ss.str ();
}